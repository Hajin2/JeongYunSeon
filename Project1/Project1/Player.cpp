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
	m_MapDraw.DrawMidText("공격력 = " + to_string(m_Info.Attack) + "\t생명력 = " + to_string(m_Info.CurLife) + "/" + to_string(m_Info.MaxLife), WIDTH, HEIGHT/2 + 1);
	getch();
}
Player::~Player()
{
}
