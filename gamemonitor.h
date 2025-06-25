#pragma once
#include "database.h"
#include "button.h"
#include "img_component.h"
#include "piece.h"

class gamemonitor
{
protected:
	vector<button*> buttons;
	vector<component*> start_component;
	vector<component*> play_component;
	vector<IMAGE> bgs;
	vector<piece*> pies;
	vector<time_t> times;
	EASYXMSG mouse;
	time_t timer;
	time_t timer2;
	int difficulty;
	int finish;
	bool bgm;
	bool LButDown;
public:
	int windowid;
	int pictureid;

	gamemonitor();
	~gamemonitor();
	void play_bgm();
	void load_button(button* but);
	void load_s_component(component* comp);
	void load_p_component(component* comp);
	void load_bg(IMAGE bg);
	virtual void m_mouse_s();
	virtual void paint_s();
	virtual void update();
	void playing();
	void end(time_t s_time);
	void paint_p();
	void m_mouse_p();
	bool gameover();
};

//class start_gm :public gamemonitor
//{
//	//static start_gm* pstart;
//public:
//	//start_gm() { pstart = this; };
//	//start_gm* getinstance() { return pstart; };
//	virtual void m_mouse();
//	virtual void paint();
//	virtual void update();
//};
//
//class play_gm :public gamemonitor
//{
//	//static play_gm* pplay;
//public:
//	//play_gm() { pplay = this; };
//	//play_gm* getinstance() { return pplay; };
//	virtual void m_mouse() {};
//	virtual void paint() {};
//	virtual void update() {};
//};
//
//class finish_gm :public gamemonitor
//{
//public:
//	virtual void m_mouse() {};
//	virtual void paint() {};
//	virtual void update() {};
//};