#include "Player.h"

Player::Player()
{
	m_Info.Attack = 5;
	m_Info.CurLife = 50;
	m_Info.MaxLife = 50;
	m_Info.CurExp = 0;
	m_Info.MaxExp = 10;
	m_Info.GetExp = 0;
	m_Info.Gold = 0;
	m_Info.Level = 1;
}
void Player::ShowInfo()
{
	system("cls");
	BLUE;
	m_MapDraw.BoxDraw(0, 0, WIDTH, HEIGHT);
	YELLOW;
	m_MapDraw.DrawMidText("======"+m_Info.Name+"("+to_string(m_Info.Level)+"Lv)======", WIDTH, HEIGHT / 2);
	m_MapDraw.TextDraw("���ݷ� = " + to_string(m_Info.Attack) + "       ����� = " + to_string(m_Info.CurLife) + "/" + to_string(m_Info.MaxLife), WIDTH / 2, HEIGHT / 2 + 1);
	m_MapDraw.TextDraw("����ġ = " + to_string(m_Info.CurExp) + "/" + to_string(m_Info.MaxExp) + "    GetEXP: " + to_string(m_Info.GetExp), WIDTH / 2, HEIGHT / 2 + 2);
	m_MapDraw.TextDraw("Gold = " + to_string(m_Info.Gold), WIDTH / 2, HEIGHT / 2 + 3);
	getch();
}
Player::~Player()
{
}
