#pragma once
#include"Macro.h"
#include"MapDraw.h"
#include"Actor.h"

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

class Player : public Actor
{
private:
	MapDraw m_MapDraw;

public:
	Player();
	~Player();
	void ShowInfo();
	inline void InputName(string Name)
	{
		m_Info.Name = Name;
	}
};

