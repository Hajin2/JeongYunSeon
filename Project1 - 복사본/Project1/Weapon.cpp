#include "Weapon.h"

Weapon::Weapon()
{
}

void Weapon::Save(ofstream& Save)
{
	switch (m_eType)
	{
	case WP_DAGGER:
		Save << "대거";
		break;
	case WP_GUN:
		Save << "총";
		break;
	case WP_SWORD:
		Save << "장검";
		break;
	case WP_WAND:
		Save << "지팡이";
		break;
	case WP_BOW:
		Save << "활";
		break;
	case WP_HAMMER:
		Save << "망치";
		break;
	}
	Save << m_strName << " " << m_iDamage << " " << m_iGold;
}
void Weapon::ShowShopInfo(int x, int y)
{
	string Type;
	switch (m_eType)
	{
	case WP_DAGGER:
		Type = "대거";
		break;
	case WP_GUN:
		Type = "총";
		break;
	case WP_SWORD:
		Type = "장검";
		break;
	case WP_WAND:
		Type = "지팡이";
		break;
	case WP_BOW:
		Type = "활";
		break;
	case WP_HAMMER:
		Type = "망치";
		break;
	}
	YELLOW
		m_MapDraw.DrawMidText("가격 : " + to_string(m_iGold) + " 무기타입 : " + Type, x, y);
	m_MapDraw.DrawMidText(" 무기이름 : " + m_strName + " 공격력 : " + to_string(m_iDamage), x, y + 1);
	ORIGINAL
}
void Weapon::ShowInfo(int x, int y)
{
	string Type;
	switch (m_eType)
	{
	case WP_DAGGER:
		Type = "대거";
		break;
	case WP_GUN:
		Type = "총";
		break;
	case WP_SWORD:
		Type = "장검";
		break;
	case WP_WAND:
		Type = "지팡이";
		break;
	case WP_BOW:
		Type = "활";
		break;
	case WP_HAMMER:
		Type = "망치";
		break;
	}
	YELLOW
		m_MapDraw.DrawMidText("무기타입 : " + Type + " 무기이름 : " + m_strName + " 공격력 : " + to_string(m_iDamage), x, y);
	ORIGINAL
}

Weapon::~Weapon()
{

}

void Bow::Attack(int DefaultDamage, Character* LoseCharacter)
{
	m_MapDraw.DrawMidText("                                              ", WIDTH, HEIGHT*0.48);
	int Damage = DefaultDamage + m_iDamage;
	if (rand() % 100 <= 10)
	{
		m_MapDraw.DrawMidText("헤드샷!!(Damage : " + to_string(Damage * 10) + ")", WIDTH, HEIGHT*0.48);
		LoseCharacter->Hit(Damage * 10);
	}
	else
		LoseCharacter->Hit(Damage);
}
Bow::Bow()
{

}
Bow::Bow(Bow* bow)
{
	m_strName = bow->m_strName;
	m_iDamage = bow->m_iDamage;
	m_iGold = bow->m_iGold;
	m_eType = bow->m_eType;
}

Bow::Bow(string Name, int Damage, int Gold)
{
	m_strName = Name;
	m_iDamage = Damage;
	m_iGold = Gold;
	m_eType = WP_BOW;
}
Bow::~Bow()
{

}


void Dagger::Attack(int DefaultDamage, Character* LoseCharacter)
{
	m_MapDraw.DrawMidText("                                              ", WIDTH, HEIGHT*0.48);
	int Damage = DefaultDamage + m_iDamage;
	if (rand() % 100 <= 20)
	{
		m_MapDraw.DrawMidText("크리티컬샷!!(Damage : " + to_string(Damage * 5) + ")", WIDTH, HEIGHT*0.48);
		LoseCharacter->Hit(Damage * 5);
		getch();
		m_MapDraw.DrawMidText("크리티컬샷!!(Damage : " + to_string(Damage * 5) + ")", WIDTH, HEIGHT*0.48);
		LoseCharacter->Hit(Damage * 5);
	}
	else
		LoseCharacter->Hit(Damage);
}
Dagger::Dagger()
{

}
Dagger::Dagger(Dagger* dagger)
{
	m_strName = dagger->m_strName;
	m_iDamage = dagger->m_iDamage;
	m_iGold = dagger->m_iGold;
	m_eType = dagger->m_eType;
}

void Save(ofstream& Save)
{

}
Dagger::Dagger(string Name, int Damage, int Gold)
{
	m_strName = Name;
	m_iDamage = Damage;
	m_iGold = Gold;
	m_eType = WP_DAGGER;
}
Dagger::~Dagger()
{

}

void Gun::Attack(int DefaultDamage, Character* LoseCharacter)
{
	m_MapDraw.DrawMidText("                                              ", WIDTH, HEIGHT*0.48);
	int Damage = DefaultDamage + m_iDamage;
	if (rand() % 100 <= 50)
	{
		m_MapDraw.DrawMidText("헤드샷!!(Damage : " + to_string(Damage * 2) + ")", WIDTH, HEIGHT*0.48);
		LoseCharacter->Hit(Damage * 2);
	}
	else
		LoseCharacter->Hit(Damage);
}
Gun::Gun()
{

}
Gun::Gun(Gun* gun)
{
	m_strName = gun->m_strName;
	m_iDamage = gun->m_iDamage;
	m_iGold = gun->m_iGold;
	m_eType = gun->m_eType;
}
Gun::Gun(string Name, int Damage, int Gold)
{
	m_strName = Name;
	m_iDamage = Damage;
	m_iGold = Gold;
	m_eType = WP_GUN;
}
Gun::~Gun()
{

}

void Sword::Attack(int DefaultDamage, Character* LoseCharacter)
{
	m_MapDraw.DrawMidText("                                              ", WIDTH, HEIGHT*0.48);
	int Damage = DefaultDamage + m_iDamage;
	if (rand() % 100 <= 30)
	{
		m_MapDraw.DrawMidText("검기!!(Damage : " + to_string(Damage * 1.5f) + ")", WIDTH, HEIGHT*0.48);
		LoseCharacter->Hit((int)((float)Damage * 1.5f));
		getch();
		m_MapDraw.DrawMidText("검기!!(Damage : " + to_string(Damage * 1.5f) + ")", WIDTH, HEIGHT*0.48);
		LoseCharacter->Hit((int)((float)Damage * 1.5f));
		getch();
		m_MapDraw.DrawMidText("검기!!(Damage : " + to_string(Damage * 1.5f) + ")", WIDTH, HEIGHT*0.48);
		LoseCharacter->Hit((int)((float)Damage * 1.5f));
	}
	else
		LoseCharacter->Hit(Damage);
}
Sword::Sword()
{

}
Sword::Sword(Sword* sword)
{
	m_strName = sword->m_strName;
	m_iDamage = sword->m_iDamage;
	m_iGold = sword->m_iGold;
	m_eType = sword->m_eType;
}

Sword::Sword(string Name, int Damage, int Gold)
{
	m_strName = Name;
	m_iDamage = Damage;
	m_iGold = Gold;
	m_eType = WP_SWORD;
}

Sword::~Sword()
{

}

void Wand::Attack(int DefaultDamage, Character* LoseCharacter)
{
	m_MapDraw.DrawMidText("                                              ", WIDTH, HEIGHT*0.48);
	int Damage = DefaultDamage + m_iDamage;
	if (rand() % 100 <= 5)
	{
		m_MapDraw.DrawMidText("즉사!!(Damage : " + to_string(Damage * 1000) + ")", WIDTH, HEIGHT*0.48);
		LoseCharacter->Hit(Damage * 1000);
	}
	else
		LoseCharacter->Hit(Damage);
}

Wand::Wand()
{

}

Wand::Wand(Wand* wand)
{
	m_strName = wand->m_strName;
	m_iDamage = wand->m_iDamage;
	m_iGold = wand->m_iGold;
	m_eType = wand->m_eType;
}

Wand::Wand(string Name, int Damage, int Gold)
{
	m_strName = Name;
	m_iDamage = Damage;
	m_iGold = Gold;
	m_eType = WP_WAND;
}

Wand::~Wand()
{

}

void Hammer::Attack(int DefaultDamage, Character* LoseCharacter)
{
	m_MapDraw.DrawMidText("                                              ", WIDTH, HEIGHT*0.48);
	int Damage = DefaultDamage + m_iDamage;
	if (rand() % 100 <= 50)
	{
		m_MapDraw.DrawMidText("던지기!!(Damage : " + to_string(Damage * 1.2f) + ")", WIDTH, HEIGHT*0.48);
		LoseCharacter->Hit((int)((float)Damage * 1.2f));
	}
	else
		LoseCharacter->Hit(Damage);
}

Hammer::Hammer()
{

}

Hammer::Hammer(Hammer* hammer)
{
	m_strName = hammer->m_strName;
	m_iDamage = hammer->m_iDamage;
	m_iGold = hammer->m_iGold;
	m_eType = hammer->m_eType;
}

Hammer::Hammer(string Name, int Damage, int Gold)
{
	m_strName = Name;
	m_iDamage = Damage;
	m_iGold = Gold;
	m_eType = WP_WAND;
}

Hammer::~Hammer()
{

}