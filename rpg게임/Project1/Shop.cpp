#include "Shop.h"

Shop::Shop()
{
	m_iWeaponCount = 0;
	ifstream Load;
	string strName;
	string strType;
	int iDamage;
	int iGold;
	Load.open("WeaponList.txt");
	m_pWeaponList = new Weapon*[GetWeaponCount()];
	if (Load.is_open())
	{
		while (!Load.eof())
		{
			Load >> strType;
			Load >> strName;
			Load >> iDamage;
			Load >> iGold;
			if (strType == "Bow")
				m_pWeaponList[m_iWeaponCount] = new Bow(strName, iDamage, iGold);
			else if (strType == "Dagger")
				m_pWeaponList[m_iWeaponCount] = new Dagger(strName, iDamage, iGold);
			else if (strType == "Gun")
				m_pWeaponList[m_iWeaponCount] = new Gun(strName, iDamage, iGold);
			else if (strType == "Sword")
				m_pWeaponList[m_iWeaponCount] = new Sword(strName, iDamage, iGold);
			else if (strType == "Wand")
				m_pWeaponList[m_iWeaponCount] = new Wand(strName, iDamage, iGold);
			else if (strType == "Hammer")
				m_pWeaponList[m_iWeaponCount] = new Hammer(strName, iDamage, iGold);
			m_iWeaponCount++;
		}
	}
}
int Shop::GetWeaponCount()
{
	ifstream Load;
	Load.open("WeaponList.txt");
	int count = 0;
	string str;
	if (Load.is_open())
	{
		while (Load.eof() == false)
		{
			getline(Load, str);
			count++;
		}
	}
	return count;
}

void Shop::ShopMenu(Character* Player)
{
	int index;
	while (1)
	{
		m_MapDraw.BoxErase(WIDTH, HEIGHT);
		m_MapDraw.DrawMidText("♧ ♣ S H O P ♣ ♧", WIDTH, HEIGHT*0.3);
		m_MapDraw.DrawMidText("Dagger", WIDTH, HEIGHT*0.3 + 2);
		m_MapDraw.DrawMidText("Gun", WIDTH, HEIGHT*0.3 + 4);
		m_MapDraw.DrawMidText("Sword", WIDTH, HEIGHT*0.3 + 6);
		m_MapDraw.DrawMidText("Wand", WIDTH, HEIGHT*0.3 + 8);
		m_MapDraw.DrawMidText("Bow", WIDTH, HEIGHT*0.3 + 10);
		m_MapDraw.DrawMidText("Hammer", WIDTH, HEIGHT*0.3 + 12);
		m_MapDraw.DrawMidText("돌아가기", WIDTH, HEIGHT*0.3 + 14);
		index = m_MapDraw.MenuSelectCursor(7, 2, (WIDTH - strlen("Hammer") / 2 - 3) / 2, HEIGHT*0.3 + 2);
		if (index == 7)
			return;
		else
			WeaponMenu(Player, (WEAPON)(index - 1));
	}
}
string Shop::GetTypeString(WEAPON Type)
{
	switch (Type)
	{
	case WP_DAGGER:
		return "Dagger";
	case WP_GUN:
		return "Gun";
	case WP_SWORD:
		return "Sword";
	case WP_WAND:
		return "Wand";
	case WP_BOW:
		return "Bow";
	case WP_HAMMER:
		return "Hammer";
	}
}
void Shop::WeaponMenu(Character* Player, WEAPON Type)
{
	int Page = 0, i = 0, count = 0;
	bool PageFlag;
	int index, NextIndex, BeforeIndex, MenuCount = 0, Line;
	int y = HEIGHT * 0.2;
	int arrindex[5];
	while (1)
	{
		Line = 0;
		count = 0;
		MenuCount = 0;
		m_MapDraw.BoxErase(WIDTH, HEIGHT);
		m_MapDraw.DrawMidText("보유 Gold : " + to_string(Player->GetGold()), WIDTH, y - 4);
		m_MapDraw.DrawMidText(GetTypeString(Type) + " Shop", WIDTH, y - 2);
		for (i = 0; i < m_iWeaponCount; i++)
		{
			if (m_pWeaponList[i]->GetType() == Type)
			{
				if (count >= Page && count < Page + 5)
				{
					m_pWeaponList[i]->ShowShopInfo(WIDTH, y + Line++ * 3);
					arrindex[MenuCount] = i;
					MenuCount++;
				}
				count++;
			}
		}
		if (count > Page + 5)
			PageFlag = true;
		else
			PageFlag = false;
		m_MapDraw.DrawMidText("이전페이지", WIDTH, y + Line++ * 3);
		m_MapDraw.DrawMidText("다음페이지", WIDTH, y + Line++ * 3);
		m_MapDraw.DrawMidText("나가기", WIDTH, y + Line * 3);
		MenuCount += 3;
		index = m_MapDraw.MenuSelectCursor(MenuCount, 3, 5, y);
		if (index == MenuCount)
			return;
		else if (index == MenuCount - 1 && PageFlag)
			Page += 5;
		else if (index == MenuCount - 2 && Page - 5 >= 0)
			Page -= 5;
		else if (index >= 1 && index <= MenuCount - 3)
		{
			if (Player->GetGold() >= m_pWeaponList[arrindex[index - 1]]->GetGold())
			{
				Weapon* weapon;
				switch (Type)
				{
				case WP_DAGGER:
					Player->Buy(new Dagger((Dagger*)(m_pWeaponList[arrindex[index - 1]])));
					break;
				case WP_GUN:
					Player->Buy(new Gun((Gun*)(m_pWeaponList[arrindex[index - 1]])));
					break;
				case WP_SWORD:
					Player->Buy(new Sword((Sword*)(m_pWeaponList[arrindex[index - 1]])));
					break;
				case WP_WAND:
					Player->Buy(new Wand((Wand*)(m_pWeaponList[arrindex[index - 1]])));
					break;
				case WP_BOW:
					Player->Buy(new Bow((Bow*)(m_pWeaponList[arrindex[index - 1]])));
					break;
				case WP_HAMMER:
					Player->Buy(new Hammer((Hammer*)(m_pWeaponList[arrindex[index - 1]])));
					break;
				}
			}
		}
	}
}

Shop::~Shop()
{
	if (m_pWeaponList != NULL)
		delete[] m_pWeaponList;
}
