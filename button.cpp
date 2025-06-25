#include "button.h"

extern int pictureid;

f_button::f_button(string id, int bx, int by)
{
	imgid = id;
	x = bx;
	y = by;
	needpaint = 1;
	loadimage(&img, imgid.c_str());
}
s_button::s_button(string id, int bx, int by)
{
	imgid = id;
	x = bx;
	y = by;
	needpaint = 1;
	loadimage(&img, imgid.c_str());
}
b_button::b_button(string id, int bx, int by)
{
	imgid = id;
	x = bx;
	y = by;
	needpaint = 1;
	loadimage(&img, imgid.c_str());
}
bgm_button::bgm_button(string id, int bx, int by)
{
	imgid = id;
	x = bx;
	y = by;
	needpaint = 1;
	loadimage(&img, imgid.c_str());
}

void button::paintbutton()
{
	putimage(x, y, &img, SRCAND);
}

int f_button::is_click(EASYXMSG mouse, int& winid, bool& tri)
{
	if (mouse.x <= x + 120 && mouse.x >= x
		&& mouse.y >= y && mouse.y <= y + 170)
	{
		winid--;
		Sleep(100);
	}
	return 0;
}

int b_button::is_click(EASYXMSG mouse, int& winid, bool& tri)
{
	if (mouse.x <= x + 120 && mouse.x >= x
		&& mouse.y >= y && mouse.y <= y + 170)
	{
		winid++;
		Sleep(100);
	}
	return 0;
}

int s_button::is_click(EASYXMSG mouse, int& winid, bool& tri)
{
	if (mouse.x <= x + 400 && mouse.x >= x
		&& mouse.y >= y - 50 && mouse.y <= y + 130
		)
	{
		Sleep(100);
		return 1;
	}
	return 0;
}

int bgm_button::is_click(EASYXMSG mouse, int& winid,bool &tri)
{
	if (mouse.x <= x + 74 && mouse.x >= x
		&& mouse.y >= y  && mouse.y <= y + 76
		)
	{
		if (tri)
		{
			PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		}
		else
		{
			PlaySound(TEXT("res/fate-to-zero.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		}
		tri = !tri;
		Sleep(100);
	}
	return 0;
}