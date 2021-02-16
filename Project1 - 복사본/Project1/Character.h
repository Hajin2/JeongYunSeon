#pragma once
#include "Macro.h"
#include "MapDraw.h"
#include"Weapon.h"
struct Info
{
	string Name;
	int Level;
	int Attack;
	int CurLife;
	int MaxLife;
	int CurExp;
	int MaxExp;
	int GetExp;
	int Gold;
};

enum CHARACTER
{
	CH_PLAYER,
	CH_MONSTER
};
class Weapon;
class Character
{
private:
	Info m_Info;
	MapDraw m_MapDraw;
	CHARACTER m_eType;
	Weapon *m_Weapon;
public:
	Character();
	~Character();
	void ShowInfo(int x, int y);
	void SetInfo(ifstream& Load, CHARACTER Type, STARTTYPE StartType);
	inline void ResetLife()
	{
		m_Info.CurLife = m_Info.MaxLife;
	}
};

