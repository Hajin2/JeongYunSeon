#include "Character.h"

Character::Character()
{
}
void Character::ShowInfo(int x, int y)
{
	m_MapDraw.gotoxy(x, y);
	cout << "     ======" << m_Info.Name << "(" << m_Info.Level << "Lv)======" << endl;
	m_MapDraw.gotoxy(x, y + 1);
	cout << "���ݷ� = " << m_Info.Attack << "\t����� = " << m_Info.CurLife << "/" << m_Info.MaxLife << endl;
	m_MapDraw.gotoxy(x, y + 2);
	cout << "����ġ = " << m_Info.CurExp << "/" << m_Info.MaxExp << "\tGetEXP : " << m_Info.GetExp << endl;
	m_MapDraw.gotoxy(x, y + 3);
	cout << "Gold = " << m_Info.Gold << endl;
}
void Character::SetInfo(ifstream& Load, CHARACTER Type, STARTTYPE StartType)
{
	int tmp;
	string strtmp;
	string strName;
	int iDamage;
	int iGold;
	m_eType = Type;
	if (m_eType == CH_PLAYER && StartType == STARTTYPE_NEWSTART)
	{
		YELLOW
			m_MapDraw.DrawMidText("Player �̸� �Է� : ", WIDTH, HEIGHT*0.5);
		cin >> m_Info.Name;
		ORIGINAL
	}
	else
		Load >> m_Info.Name;
	Load >> m_Info.Attack;
	Load >> m_Info.MaxLife;
	Load >> m_Info.MaxExp;
	Load >> m_Info.GetExp;
	Load >> m_Info.Level;
	Load >> m_Info.Gold;
	if (StartType == STARTTYPE_LOADSTART)
	{
		Load >> m_Info.CurExp;
		Load >> m_Info.CurLife;
		if (m_eType == CH_PLAYER)
		{
			Load >> tmp;
			if (tmp)
			{
				Load >> strtmp;
				Load >> strName;
				Load >> iDamage;
				/*if (strtmp == "���")
					m_Weapon = new Dagger(strName, iDamage, iGold);
				else if (strtmp == "��")
					m_Weapon = new Gun(strName, iDamage, iGold);
				else if (strtmp == "���")
					m_Weapon = new Sword(strName, iDamage, iGold);
				else if (strtmp == "������")
					m_Weapon = new Wand(strName, iDamage, iGold);
				else if (strtmp == "Ȱ")
					m_Weapon = new Bow(strName, iDamage, iGold);
				else if (strtmp == "��ġ")
					m_Weapon = new Hammer(strName, iDamage, iGold);*/
			}
		}
	}
	else
	{
		m_Info.CurExp = 0;
		ResetLife();
	}
}
Character::~Character()
{
}

