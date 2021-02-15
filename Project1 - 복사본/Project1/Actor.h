#pragma once
#include "Macro.h"

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

class Actor
{
protected:
	Info m_Info;
	
public:
	Actor();
	virtual ~Actor();
	virtual void ShowInfo() = 0;
};

