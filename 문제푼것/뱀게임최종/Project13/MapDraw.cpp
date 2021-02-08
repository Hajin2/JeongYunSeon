#include "MapDraw.h"
void MapDraw::BoxDraw()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (x == 0 || x == WIDTH - 1 || y == 0 || y == HEIGHT - 1)
				cout << WALL;
			else
				cout << "  ";
		}
		cout << endl;
	}
}
void MapDraw::ErasePoint(int x, int y)
{
	gotoxy(2 * x, y);
	cout << "  ";
	gotoxy(-1, -1);
	return;
}
void MapDraw::DrawPoint(string str, int x, int y)
{
	gotoxy(2 * x, y);
	cout << str;
	gotoxy(-1, -1);
	return;
}
void MapDraw::DrawMidText(string str, int x, int y)
{
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << str;
	return;
}
