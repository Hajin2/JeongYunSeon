#include "Character.h"

Character::Character()
{
}
void Character::ShowInfo(int x, int y)
{
	m_MapDraw.gotoxy(x, y);
	cout << "     ======" << m_Info.Name << "(" << m_Info.Level << "Lv)======" << endl;
	m_MapDraw.gotoxy(x, y + 1);
	cout << "공격력 = " << m_Info.Attack << "\t생명력 = " << m_Info.CurLife << "/" << m_Info.MaxLife << endl;
	m_MapDraw.gotoxy(x, y + 2);
	cout << "경험치 = " << m_Info.CurExp << "/" << m_Info.MaxExp << "\tGetEXP : " << m_Info.GetExp << endl;
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
			m_MapDraw.DrawMidText("Player 이름 입력 : ", WIDTH, HEIGHT*0.5);
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
				/*if (strtmp == "대거")
					m_Weapon = new Dagger(strName, iDamage, iGold);
				else if (strtmp == "총")
					m_Weapon = new Gun(strName, iDamage, iGold);
				else if (strtmp == "장검")
					m_Weapon = new Sword(strName, iDamage, iGold);
				else if (strtmp == "지팡이")
					m_Weapon = new Wand(strName, iDamage, iGold);
				else if (strtmp == "활")
					m_Weapon = new Bow(strName, iDamage, iGold);
				else if (strtmp == "망치")
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
bool Character::ExpUp(Character& Enemy)
{
	int Num;
	getch();
	m_MapDraw.BoxErase(WIDTH, HEIGHT);
	m_MapDraw.DrawMidText(m_Info.Name + " 승리!!", WIDTH, HEIGHT * 0.3);
	m_MapDraw.DrawMidText(m_Info.Name + "가 경험치 " + to_string(Enemy.GetExp()) + "를 얻었습니다.", WIDTH, HEIGHT* 0.4);
	m_Info.CurExp += Enemy.GetExp();
	if (Enemy.GetType() == CH_PLAYER)
		Enemy.ResetExp();
	if (m_Info.CurExp >= m_Info.MaxExp)
	{
		getch();
		LevelUp();
	}
	if (Enemy.GetType() == CH_PLAYER && Enemy.GetExp() == 0)
	{
		getch();
		m_MapDraw.DrawMidText("Game Over", WIDTH, HEIGHT*0.5);
		getch();
		return false;
	}

	if (m_eType == CH_PLAYER)
	{
		m_Info.GetExp = m_Info.CurExp;
		m_Info.Gold += Enemy.GetGold();
	}
	Enemy.ResetLife();
	getch();
	return true;
}
void Character::LevelUp()
{
	int Num;
	PUPPLE
		m_MapDraw.BoxErase(WIDTH, HEIGHT);
	m_MapDraw.DrawMidText(m_Info.Name + "레벨업!!", WIDTH, HEIGHT*0.4);
	Num = rand() % (UPATTACKSTAT + 1);
	m_Info.Attack += Num;
	m_MapDraw.DrawMidText("공격력 " + to_string(Num) + " 증가!!", WIDTH, HEIGHT*0.5);
	Num = rand() % (UPLIFESTAT + 1);
	m_Info.MaxLife += Num;
	m_MapDraw.DrawMidText("생명력 " + to_string(Num) + " 증가!!", WIDTH, HEIGHT*0.6);
	m_Info.CurExp = 0;
	m_Info.MaxExp += m_Info.MaxExp * 0.3;
	m_Info.Level++;
	m_Info.CurLife = m_Info.MaxLife;
	ORIGINAL
}
RPS Character::GetRPS()
{
	char ch;
	if (m_eType == CH_MONSTER)
		return (RPS)(rand() % RPS_END);
	else if (m_eType == CH_PLAYER)
	{
		while (1)
		{
			ch = getch() - 49;
			if (ch >= RPS_START && ch < RPS_END)
				return (RPS)ch;
		}
	}
}
void Character::Attack(Character* Enemy)
{
	if (m_Weapon)
		m_Weapon->Attack(m_Info.Attack, Enemy);
	else
		Enemy->Hit(m_Info.Attack);
}
void Character::Hit(int Attacked)
{
	m_Info.CurLife -= Attacked;
	if (m_Info.CurLife < 0)
		m_Info.CurLife = 0;
}
Character::~Character()
{
}

