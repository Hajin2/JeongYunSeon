#pragma once
#include"Macro.h"
#include"Actor.h"
#include"MapDraw.h"

#define MAXMON 6
class Monster : public Actor
{
private:
	Info m_Info[MAXMON];
	MapDraw m_MapDraw;

public:
	void ShowInfo();
	Monster();
	~Monster();
};

