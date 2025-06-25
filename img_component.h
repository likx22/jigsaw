#pragma once
#include "database.h"

class component
{
protected:
	int x;
	int y;
	IMAGE img;
public:
	component() {};
	virtual void paintcomp() = 0;
	void putimg(int a, int b,int difficulty) { putimage(a, b, PWIDTH / difficulty, PHEIGHT / difficulty, &img,0,0); };
	IMAGE getimg() { return img; };
};

class start_comp :public component
{
public:
	start_comp(int a, int b, IMAGE im) { x = a; y = b; img = im; };
	virtual void paintcomp() {
		putimage(x, y, &img, SRCAND);
	};
};

class play_comp :public component
{
public:
	play_comp(int a, int b, IMAGE im) { x = a; y = b; img = im; };
	virtual void paintcomp() {
		putimage(x, y, &img);
	};
};