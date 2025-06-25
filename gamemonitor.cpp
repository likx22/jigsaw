#include "gamemonitor.h"
#include "processer.h"

gamemonitor::gamemonitor()
{
	finish = 0;
	windowid = 1;
	bgm = 1;
	LButDown = 0;
	difficulty = EASY;
}

gamemonitor::~gamemonitor()
{
	buttons.clear();
	buttons.shrink_to_fit();
	start_component.clear();
	start_component.shrink_to_fit();
	play_component.clear();
	play_component.shrink_to_fit();
	bgs.clear();
	bgs.shrink_to_fit();
	pies.clear();
	pies.shrink_to_fit();
	times.clear();
	times.shrink_to_fit();
}

void gamemonitor::play_bgm()
{
	PlaySound(TEXT("res/fate-to-zero.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void gamemonitor::load_button(button* but)
{
	buttons.push_back(but);
}

void gamemonitor::load_s_component(component* comp)
{
	start_component.push_back(comp);
}

void gamemonitor::load_p_component(component* comp)
{
	play_component.push_back(comp);
}

void gamemonitor::load_bg(IMAGE bg)
{
	bgs.push_back(bg);
}

void gamemonitor::m_mouse_s()
{
	peekmessage(&mouse, EM_MOUSE);
	if (mouse.message == WM_LBUTTONDOWN)
	{
		for (button* but : buttons)
		{
			if (but->is_click(mouse, windowid,bgm))
			{
				pictureid = windowid;
				playing();
			}
			if (windowid < 0)
				windowid = 0;
			else if (windowid > bgs.size() - 2)
				windowid = bgs.size() - 2;
		}
	}
}

void gamemonitor::paint_s()
{
	BeginBatchDraw();
	putimage(0, 0, &bgs[windowid]);
	for (component* com : start_component)
	{
		com->paintcomp();
	}
	for (button* but : buttons)
	{
		if (but->needpaint)
		{
			but->paintbutton();
		}
	}
	EndBatchDraw();
}

void gamemonitor::update()
{
	time(&timer2);
	while (1)
	{
		time(&timer);
		if (timer - timer2 >= 1)
		{
			timer2 = timer;
			paint_s();
			buttons[2]->needpaint = !buttons[2]->needpaint;
			if(bgm)
				rotateimage(&buttons[3]->img, &buttons[3]->img, PI / 6);
			//break;
		}
		m_mouse_s();
	}
}

void gamemonitor::playing()
{
	time_t start_time;
	time(&start_time);
	int a, b;
	int count = 0;
	array<int, 25 > arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };
	srand((unsigned int)time(nullptr));
	random_shuffle(arr.begin(), arr.begin() + difficulty * difficulty - 1);
	for (int i = 0; i < difficulty; i++)
	{
		for (int j = 0; j < difficulty; j++)
		{
			a = 400 + (PWIDTH / difficulty) * j;
			b = 50 + (PHEIGHT / difficulty) * i;
			bool needrotate = rand() % 2;
			if (!needrotate)
			{
				pies.push_back(new piece(a, b, arr[count], difficulty, 0));
			}
			else
			{
				pies.push_back(new piece(a, b, arr[count], difficulty, 1));
			}
			count++;
		}
	}
	while (1)
	{
		paint_p();
		m_mouse_p();
		if (gameover())
		{
			end(start_time);
			break;
		}
	}
}

void gamemonitor::end(time_t s_time)
{
	time_t end_time;
	time(&end_time);
	char time_use[13];
	_itoa_s(end_time - s_time, time_use, 13, 10);
	times.push_back(end_time - s_time);
	BeginBatchDraw();
	paint_p();
	setcolor(WHITE);
	settextstyle(60, 0, _T("华文新魏"));
	outtextxy(850, 100, time_use);
	for (piece* pie : pies)
	{
		pie->paintpiece(difficulty, play_component[pictureid * 3 + 1]->getimg());
	}
	if ((end_time - s_time) <= *min_element(times.begin(), times.end()))
	{
		setcolor(BLUE);
		settextstyle(50, 0, _T("华文新魏"));
		outtextxy(780, 160, "New Record!");
	}
	EndBatchDraw();
	Sleep(3000);
	difficulty++;
	if (difficulty > HARD)
	{
		difficulty = EASY;
	}
	pies.clear();
	windowid = (pictureid + 1) % 2;
}

void gamemonitor::paint_p()
{
	BeginBatchDraw();
	putimage(0, 0, &bgs[bgs.size()-1]);
	play_component[0]->paintcomp();
	play_component[pictureid * 3 + 3]->paintcomp();
	for (piece* pie : pies)
	{		
		if (mouse.x <= pie->x + PWIDTH / difficulty && mouse.x >= pie->x
			&& mouse.y >= pie->y && mouse.y <= pie->y + PHEIGHT / difficulty
			&&!LButDown)
			play_component[play_component.size() - 1]->putimg(pie->x + 15, pie->y + 10,difficulty);
		if (!pie->reverse)
			pie->paintpiece(difficulty, play_component[pictureid*3+1]->getimg());
		else
			pie->paintpiece_r(difficulty, play_component[pictureid*3+2]->getimg());

	}
	EndBatchDraw();
}

void gamemonitor::m_mouse_p()
{
	peekmessage(&mouse, EM_MOUSE);
	if (mouse.message == WM_LBUTTONDOWN)
	{
		for (piece* pie : pies)
		{
			if (mouse.x <= pie->x + PWIDTH / difficulty && mouse.x >= pie->x
				&& mouse.y >= pie->y && mouse.y <= pie->y + PHEIGHT / difficulty)
			{
				LButDown = 1;
				while (1)
				{
					peekmessage(&mouse, EM_MOUSE);
					if (mouse.message == WM_LBUTTONUP)
					{
						if (mouse.x <= pie->x_ans + PWIDTH / difficulty && mouse.x >= pie->x_ans
							&& mouse.y >= pie->y_ans && mouse.y <= pie->y_ans + PHEIGHT / difficulty)
						{
							pie->x = pie->x_ans;
							pie->y = pie->y_ans;
						}
						else
						{
							pie->x = pie->x_start;
							pie->y = pie->y_start;
						}
						LButDown = 0;
						break;
					}
					else
					{
						pie->x = mouse.x - 0.5 * PWIDTH / difficulty;
						pie->y = mouse.y - 0.5 * PHEIGHT / difficulty;
					}
					paint_p();
				}
			}
		}
	}
	else if (mouse.message == WM_RBUTTONDOWN)
	{
		for (piece* pie : pies)
		{
			if (mouse.x <= pie->x + PWIDTH / difficulty && mouse.x >= pie->x
				&& mouse.y >= pie->y && mouse.y <= pie->y + PHEIGHT / difficulty)
			{
				pie->reverse = !pie->reverse;
				Sleep(100);
			}
		}
	}
}

bool gamemonitor::gameover()
{
	for (piece* pie : pies)
	{
		if (!pie->correct())
			return false;
	}
	return true;
}
