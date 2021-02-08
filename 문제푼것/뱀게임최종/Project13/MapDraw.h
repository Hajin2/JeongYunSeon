#pragma once
#include"Macro.h"

class MapDraw
{
public:
	void BoxDraw();
	void DrawPoint(string str, int x, int y);
	void ErasePoint(int x, int y);
	void DrawMidText(string str, int x, int y);
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};

