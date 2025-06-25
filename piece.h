#pragma once
#include "database.h"

class piece
{
public:
	int x;
	int y;
	int x_start;
	int y_start;
	int x_ans;
	int y_ans;
	int id;
	bool ischosen;
	bool reverse;

	piece(int a, int b, int i, int dif, int rev);
	bool correct();
	void paintpiece(int difficulty,IMAGE img);
	void paintpiece_r(int difficulty, IMAGE img);
};