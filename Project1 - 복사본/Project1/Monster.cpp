#include "Monster.h"



Monster::Monster()
{
	m_Info[0] = { "고블린", 1, 3, 20, 20, 0, 5, 5, 5 };
	m_Info[1] = { "오크", 1, 20, 100, 100, 0, 20, 50, 10 };
	m_Info[2] = { "늑대인간", 1, 50, 250, 250, 0, 50, 250, 20 };
	m_Info[3] = { "오우거", 1, 120, 500, 500, 0, 500, 700, 40 };
	m_Info[4] = { "스켈레톤아처", 1, 200, 800, 800, 0, 200, 1500, 80 };
	m_Info[5] = { "리치", 1, 300, 3000, 3000, 0, 300, 3000, 160 };
}
Monster::~Monster()
{
}

void Monster::ShowInfo()
{
	system("cls");
	BLUE;
	m_MapDraw.BoxDraw(0, 0, WIDTH, HEIGHT);
	ORIGINAL;
	for (int i = 0; i < 6; i++)
	{
		m_MapDraw.DrawMidText("======" + m_Info[i].Name + "(" + to_string(m_Info[i].Level) + "Lv)======", WIDTH, 4 * i + 3);
		m_MapDraw.TextDraw("공격력 = " + to_string(m_Info[i].Attack) + "       생명력 = " + to_string(m_Info[i].CurLife) + "/" + to_string(m_Info[i].MaxLife), WIDTH / 2, 4 * i + 4);
		m_MapDraw.TextDraw("경험치 = " + to_string(m_Info[i].CurExp) + "/" + to_string(m_Info[i].MaxExp) + "    GetEXP: " + to_string(m_Info[i].GetExp), WIDTH / 2, 4 * i + 5);
		m_MapDraw.TextDraw("Gold = " + to_string(m_Info[i].Gold), WIDTH / 2, 4 * i + 6);
	}
	getch();
}
