#pragma once
#include "gamemonitor.h"

class processer
{
public:
	static gamemonitor* start;
	static gamemonitor* play;
	static gamemonitor* finish;
	static gamemonitor* gm;

	processer() {};
	static void change_to_start() { gm = start; };
	static void change_to_play() { gm = play; };
	static void change_to_finish() { gm = finish; };
	//void update() { gm->update(); gm = gm->pnext; };
};
