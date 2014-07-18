#include "Lee.h"


CLee::CLee(void)
{
	H = 4;
	W = 6;
	WALL = -1;
	FREE = -2;
	grid = new int *[H];
	for (int i(0); i < W; i++)
		grid[i] = new int [W];
	px = new int [W * H];
	py = new int [W * H];
}

bool CLee::Find(int axT, int ayT, int bxT, int byT)
{
	ax = axT;
	ay = ayT;
	bx = bxT;
	by = byT;
	int grid[4][6] = {{-2, -2, -2, -2, -2, -2},
					{-2, -1, -2, -1, -1, -2},
					{-2, -1, -2, -2, -2, -2},
					{-2, -2, -2, -1, -2, -2}
					 };
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	int d, x, y, k;
	bool stop;

	d = 0;
	grid[ay][ax] = 0;

	do {
		stop = true;
		for (y = 0; y < H; y++)
			for (x = 0; x < W; x++)
				if (grid[y][x] == d)
				{
					for (k = 0; k < 4; k++)
					{
						if ((grid[y + dy[k]][x + dx[k]] == FREE) && ((y + dy[k]) >= 0) && ((y + dy[k]) < H) && ((x + dx[k]) >= 0) && ((x + dx[k]) < W))
						{
							stop = false;
							grid[y + dy[k]][x + dx[k]] = d + 1;
						}
					}
				}
			d++;	
	} while (!stop && grid[by][bx] == FREE);

	for (int i(0); i < H; i++)
		for (int j(0); j < W; j++)
			CLee::grid[i][j] = grid[i][j];
	if (grid[by][bx] == FREE) return false;

	len = grid[by][bx];
	x = bx;
	y = by;
	d = len;
	while (d > 0)
	{
		px[d] = x;
		py[d] = y;
		d--;
		for (k = 0; k < 4; k++)
		{
			if (grid[y + dy[k]][x + dx[k]] == d)
				{
					x = x + dx[k];
					y = y + dy[k];
					break;
				}
		}
	}
	px[0] = ax;
	py[0] = ay;
	return true;
}

void CLee::Display()
{
	bool res = Find(ax, ay, bx, by);
	if (!res)
		std::cout << "Not path fount\n";
	else {
		for (int i(0); i <= len; i++)
		{
			std::cout <<px[i] << " " << py[i] <<" ->";
		}
		std::cout <<std::endl;
		std::cout <<std::endl;
	}
	for (int i(0); i < H; i++)
	{
		for (int j(0); j < W; j++)
			std::cout << std::setw(2) << grid[i][j];
		std::cout << std::endl;
	}
}

CLee::~CLee(void)
{

}
