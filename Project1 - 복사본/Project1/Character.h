#pragma once
#include "Macro.h"
#include "MapDraw.h"
#include"Weapon.h"

#define UPATTACKSTAT 4
#define UPLIFESTAT 10

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
enum RPS
{
	RPS_START,
	RPS_SCISSOR = 0,
	RPS_ROCK,
	RPS_PAPER,
	RPS_END
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
	bool ExpUp(Character& Enemy);
	void LevelUp();
	void Attack(Character* Enemy);
	void Hit(int Attacked);
	void Save(ofstream& Save);
	void Buy(Weapon *weapon);
	RPS GetRPS();
	inline void ResetExp()
	{
		m_Info.CurExp = 0;
		m_Info.GetExp = 0;
	}
	inline void ResetLife()
	{
		m_Info.CurLife = m_Info.MaxLife;
	}
	inline void DeleteWeapon()
	{
		if (m_Weapon)
			delete m_Weapon;
	}
	inline int GetExp()
	{
		return m_Info.GetExp;
	}
	inline int GetAttack()
	{
		return m_Info.Attack;
	}
	inline CHARACTER GetType()
	{
		return m_eType;
	}
	inline string GetName()
	{
		return m_Info.Name;
	}
	inline int GetGold()
	{
		return m_Info.Gold;
	}
	inline int GetLife()
	{
		return m_Info.CurLife;
	}
};

