#pragma once

#include <iostream>
#include <iomanip>

class CLee
{
public:
	CLee(void);
	~CLee(void);
	bool Find(int axT, int ayT, int bxT, int byT);
	void Display();

private:
	int H;
	int W;
	int WALL;
	int FREE;
	int *px, *py;
	int len;
	int **grid;
	int ax, ay, bx, by;
};

