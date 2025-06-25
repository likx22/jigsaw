#include "piece.h"
#include "img_component.h"

piece::piece(int a, int b, int i, int dif, int rev)
{
	x = a;
	y = b;
	x_start = a;
	y_start = b;
	id = i;
	ischosen = 0;
	reverse = rev;
	x_ans = 105 + (id % dif) * (PWIDTH / dif);
	y_ans = 225 + (id / dif) * (PHEIGHT / dif);
}

bool piece::correct()
{
	if (x == x_ans && y == y_ans&&reverse==0)
		return true;
	return false;
}

//void piece::move(EASYXMSG mouse,int difficulty)
//{
//	if (mouse.x <= x + PWIDTH / difficulty && mouse.x >= x
//		&& mouse.y >= y && mouse.y <= y + PHEIGHT / difficulty)
//	{
//		while (1)
//		{
//			peekmessage(&mouse, EM_MOUSE);
//			if (mouse.message == WM_LBUTTONUP)
//			{
//				if (mouse.x <= x_ans + PWIDTH / difficulty && mouse.x >= x_ans
//					&& mouse.y >= y_ans && mouse.y <= y_ans + PHEIGHT / difficulty)
//				{
//					x = x_ans;
//					y = y_ans;
//				}
//				else
//				{
//					x = x_start;
//					y = y_start;
//				}
//				break;
//			}
//			else
//			{
//				x = mouse.x - 0.5 * PWIDTH / difficulty;
//				y = mouse.y - 0.5 * PHEIGHT / difficulty;
//			}
//		}
//	}
//}

void piece::paintpiece(int difficulty,IMAGE img)
{
	putimage(x, y, PWIDTH / difficulty, PHEIGHT / difficulty, &img, (id % difficulty) * (PWIDTH / difficulty), (id / difficulty) * (PHEIGHT / difficulty));
}

void piece::paintpiece_r(int difficulty, IMAGE img)
{
	putimage(x, y, PWIDTH / difficulty, PHEIGHT / difficulty, &img, ((difficulty * difficulty - 1 - id) % difficulty) * (PWIDTH / difficulty), ((difficulty * difficulty - 1 - id) / difficulty) * (PHEIGHT / difficulty));

}
