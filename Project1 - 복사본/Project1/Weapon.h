#pragma once
#include"MapDraw.h"
#include"Macro.h"
#include"Character.h"

enum WEAPON
{
	WP_START,
	WP_DAGGER = 0,
	WP_GUN,
	WP_SWORD,
	WP_WAND,
	WP_BOW,
	WP_HAMMER,
	WP_END
};

class Character;
class Weapon
{
protected:
	WEAPON m_eType;
	MapDraw m_MapDraw;
	string m_strName;
	int m_iDamage;
	int m_iGold;
public:
	virtual void Attack(int DefaultDamage, Character* LoseCharacter) = 0;
	void ShowInfo(int x, int y);
	void Save(ofstream& Save);
	inline WEAPON GetType()
	{
		return m_eType;
	}
	inline int GetGold()
	{
		return m_iGold;
	}
	void ShowShopInfo(int x, int y);
	Weapon();
	virtual ~Weapon();
};

class Dagger : public Weapon
{
public: 
	void Attack(int DefaultDamage, Character* LoseCharacter);
	Dagger();
	Dagger(Dagger* dagger);
	Dagger(string Name, int Damage, int Gold);
	~Dagger();
};
class Gun : public Weapon
{
public:
	void Attack(int DefaultDamage, Character* LoseCharacter);
	Gun();
	Gun(Gun* gun);
	Gun(string Name, int Damage, int Gold);
	~Gun();
};
class Sword : public Weapon
{
public:
	void Attack(int DefaultDamage, Character* LoseCharacter);
	Sword();
	Sword(Sword* sword);
	Sword(string Name, int Damage, int Gold);
	~Sword();
};
class Wand : public Weapon
{
public:
	void Attack(int DefaultDamage, Character* LoseCharacter);
	Wand();
	Wand(Wand* sword);
	Wand(string Name, int Damage, int Gold);
	~Wand();
};
class Bow : public Weapon
{
public:
	void Attack(int DefaultDamage, Character* LoseCharacter);
	Bow();
	Bow(Bow* bow);
	Bow(string Name, int Damage, int Gold);
	~Bow();
};
class Hammer : public Weapon
{
public:
	void Attack(int DefaultDamage, Character* LoseCharacter);
	Hammer();
	Hammer(Hammer* hammer);
	Hammer(string Name, int Damage, int Gold);
	~Hammer();
};