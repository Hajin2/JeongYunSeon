#pragma once
#include"Macro.h"
#include"Actor.h"

class Monster : public Actor
{
private:
	Info m_Info[6];
	
public:
	void ShowInfo();
	Monster();
	~Monster();
};

