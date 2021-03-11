#pragma once
#include"Weapon.h"
#include"MapDraw.h"
#include"Macro.h"

class Shop
{
private:
	MapDraw m_MapDraw;
	Weapon** m_pWeaponList;
	int m_iWeaponCount;

public:
	int GetWeaponCount();
	void ShopMenu(Character* Player);
	void WeaponMenu(Character* Player, WEAPON Type);
	string GetTypeString(WEAPON Type);
	Shop();
	~Shop();
};

