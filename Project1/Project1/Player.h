#pragma once
#include"Macro.h"

struct PlayerInfo
{
	string m_strName;
	int m_iAttack;
	int m_iCurLife;
	int m_iMaxLife;
	int m_iCurExp;
	int m_iMaxExp;
	int m_iGetExp;
	int m_iGold;
	int m_iLevel;
};

class Player
{
protected:
	PlayerInfo m_PInfo;

public:
	Player();
	~Player();
	inline void InputName(string Name)
	{
		m_PInfo.m_strName = Name;
	}
};

