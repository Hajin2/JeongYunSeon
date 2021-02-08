#include "Player.h"



Player::Player()
{
	m_PInfo.m_iAttack = 5;
	m_PInfo.m_iCurLife = 50;
	m_PInfo.m_iMaxLife = 50;
	m_PInfo.m_iCurExp = 0;
	m_PInfo.m_iMaxExp = 10;
	m_PInfo.m_iGetExp = 0;
	m_PInfo.m_iGold = 0;
	m_PInfo.m_iLevel = 1;
}


Player::~Player()
{
}
