#include "Player.h"

Player::Player()
{
	Reset();
}

void Player::SetName()
{
	BLUE;
	m_Interface.SetNameDraw();
	m_strName = "";
	while (WordTyping(m_strName, NAMEMAX) != KEY_ENTER)
	{
	}
	m_Interface.NameDraw(m_strName);
}

void Player::Reset()
{
	m_iScore = 0;
	m_iLife = LIFEMAX;
	m_strName = "? ? ?";
	m_bCompareState = true;
	m_bTypingState = true;
	m_strCompareWord = "";
}

KEY Player::WordTyping(string& str, int limit)
{
	KEY key = m_Interface.Typing(str, m_bTypingState);
	if (m_bCompareState)
	{
		switch (key)
		{
		case KEY_CHAR:
			m_Interface.GetDrawManager().DrawMidText(str, WIDTH, HEIGHT*0.7 + 2);
			break;
		case KEY_BACKSPACE:
			m_Interface.GetDrawManager().DrawMidText(m_Interface.AddString(" ", str.length() + 1), WIDTH, HEIGHT*0.7 + 2);
			m_Interface.GetDrawManager().DrawMidText(str, WIDTH, HEIGHT*0.7 + 2);
			if (m_bTypingState == false)
			{
				m_Interface.GetDrawManager().DrawMidText(m_Interface.AddString(" ", WIDTH*0.3 - 2), WIDTH, HEIGHT*0.6 + 1);
				m_bTypingState = true;
			}
			break;
		}
		if (m_bTypingState && str.length() >= limit)
		{
			m_Interface.GetDrawManager().DrawMidText(to_string(limit) + "글자 초과!", WIDTH, HEIGHT*0.6 + 1);
			m_bTypingState = false;
		}
		if (str.length() == 0)
			return KEY_NON;
		return key;
	}
	return KEY_NON;
}
Player::~Player()
{
}
