#pragma once
#include"Macro.h"
#include"MapDraw.h"
#include"Actor.h"

class Player : public Actor
{
private:
	MapDraw m_MapDraw;

public:
	Player();
	~Player();
	void ShowInfo();
	inline void InputName(string Name)
	{
		m_Info.Name = Name;
	}
	inline void Attacked(int Attack)
	{
		if (m_Info.CurLife > 0)
		{
			m_Info.CurLife -= Attack;
			if (m_Info.CurLife < 0)
				m_Info.CurLife = 0;
		}
	}
};

