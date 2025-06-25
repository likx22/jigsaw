#pragma once
#include "database.h"

class button
{
protected:
	string imgid;
	int x;
	int y;
public:
	IMAGE img;
	bool needpaint;

	button() {};
	~button() {};
	void paintbutton();
	virtual int is_click(EASYXMSG mouse, int& winid,bool &tri)=0;
};

class f_button :public button
{
public:
	f_button(string id, int bx, int by);
	virtual int is_click(EASYXMSG mouse, int& winid, bool &tri);
};

class b_button :public button
{
public:
	b_button(string id, int bx, int by);
	virtual int is_click(EASYXMSG mouse, int& winid, bool& tri);
};

class s_button :public button
{
public:
	s_button(string id, int bx, int by);
	virtual int is_click(EASYXMSG mouse, int& winid, bool &tri);
};

class bgm_button :public button
{
public:
	bgm_button(string id, int bx, int by);
	virtual int is_click(EASYXMSG mouse, int& winid,bool &tri);
};