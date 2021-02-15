#include "Monster.h"



Monster::Monster()
{
	m_Info[0] = { "���", 1, 3, 20, 20, 0, 5, 5, 5 };
	m_Info[1] = { "��ũ", 1, 20, 100, 100, 0, 20, 50, 10 };
	m_Info[2] = { "�����ΰ�", 1, 50, 250, 250, 0, 50, 250, 20 };
	m_Info[3] = { "�����", 1, 120, 500, 500, 0, 500, 700, 40 };
	m_Info[4] = { "���̷����ó", 1, 200, 800, 800, 0, 200, 1500, 80 };
	m_Info[5] = { "��ġ", 1, 300, 3000, 3000, 0, 300, 3000, 160 };
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
		m_MapDraw.TextDraw("���ݷ� = " + to_string(m_Info[i].Attack) + "       ����� = " + to_string(m_Info[i].CurLife) + "/" + to_string(m_Info[i].MaxLife), WIDTH / 2, 4 * i + 4);
		m_MapDraw.TextDraw("����ġ = " + to_string(m_Info[i].CurExp) + "/" + to_string(m_Info[i].MaxExp) + "    GetEXP: " + to_string(m_Info[i].GetExp), WIDTH / 2, 4 * i + 5);
		m_MapDraw.TextDraw("Gold = " + to_string(m_Info[i].Gold), WIDTH / 2, 4 * i + 6);
	}
	getch();
}
