#include "Interface.h"

Interface::Interface()
{
	m_LifePos.m_ix = 1;
	m_LifePos.m_iy = HEIGHT + 1;
	m_ScorePos.m_ix = WIDTH;
	m_ScorePos.m_iy = HEIGHT + 1;
	m_NamePos.m_ix = WIDTH * 2 - 1;
	m_NamePos.m_iy = HEIGHT + 1;

	string str;
	ifstream Load;
	Load.open(FILENAME);
	Load >> m_iStoryLineCount;
	m_strStoryList = new string[m_iStoryLineCount];
	for (int i = 0; i < m_iStoryLineCount; i++)
		getline(Load, m_strStoryList[i]);
}

void Interface::SelectColor(COLOR color)
{
	switch (color)
	{
	case COLOR_BLACK:
		BLACK;
		break;
	case COLOR_DARK_BLUE:
		DARK_BLUE;
		break;
	case COLOR_GREEN:
		GREEN;
		break;
	case COLOR_BLUE_GREEN:
		BLUE_GREEN;
		break;
	case COLOR_BLOOD:
		BLOOD;
		break;
	case COLOR_PUPPLE:
		PUPPLE;
		break;
	case COLOR_GOLD:
		GOLD;
		break;
	case COLOR_ORIGINAL:
		ORIGINAL;
		break;
	case COLOR_GRAY:
		GRAY;
		break;
	case COLOR_BLUE:
		BLUE;
		break;
	case COLOR_HIGH_GREEN:
		HIGH_GREEN;
		break;
	case COLOR_SKY_BLUE:
		SKY_BLUE;
		break;
	case COLOR_RED:
		RED;
		break;
	case COLOR_PLUM:
		PLUM;
		break;
	case COLOR_YELLOW:
		YELLOW;
		break;
	}
}

void Interface::BoxDraw(COLOR color)
{
	SelectColor(color);
	m_DrawManager.BoxDraw(0, 0, WIDTH, HEIGHT);
	ORIGINAL;
}

void Interface::SmallBoxDraw(string str)
{
	BLUE;
	m_DrawManager.BoxDraw(WIDTH, HEIGHT*0.7, WIDTH*0.3, 5);
	m_DrawManager.DrawMidText(str, WIDTH, HEIGHT*0.7 + 2);
}

void Interface::TitleDraw()
{
	SelectColor(COLOR_BLUE);
	m_DrawManager.DrawMidText("☆ ★ 베 네 치 아 ★ ☆", WIDTH, HEIGHT*0.2);
	m_DrawManager.DrawMidText("1.Game Start", WIDTH, HEIGHT*0.4);
	m_DrawManager.DrawMidText("2.Rank", WIDTH, HEIGHT*0.4 + 3);
	m_DrawManager.DrawMidText("3.Exit", WIDTH, HEIGHT*0.4 + 6);
	ORIGINAL;
}

void Interface::StoryDraw()
{
	BLUE;
	m_DrawManager.BoxErase(WIDTH, HEIGHT);
	m_DrawManager.BoxDraw(WIDTH, HEIGHT* 0.7, WIDTH* 0.3, 5);
	SmallBoxDraw("Skip : s");
	int OldClock, Curclock;
	OldClock = clock();
	int StrIndex = 1;
	int NextStrIndex = 0;
	while (1)
	{
		if (kbhit())
		{
			if (getch() == 's' || getch() == 'S')
				break;
		}
		Curclock = clock();
		if (Curclock - OldClock >= STORYTIME)
		{
			if (StrIndex <= 10)
			{
				m_DrawManager.DrawMidText(m_strStoryList[StrIndex], WIDTH, HEIGHT*0.2 + StrIndex);
				StrIndex++;
			}
			else
			{
				if (StrIndex + NextStrIndex >= m_iStoryLineCount)
					break;
				for (int i = 1; i <= 10; i++)
				{
					m_DrawManager.DrawMidText("                                        ", WIDTH, HEIGHT*0.2 + i);
				}
				NextStrIndex++;
				for (int i = 1; i <= 10; i++)
					m_DrawManager.DrawMidText(m_strStoryList[i + NextStrIndex], WIDTH, HEIGHT*0.2 + i);

			}
			OldClock = Curclock;
		}
	}
	ORIGINAL;
}

void Interface::StageDraw(int stage)
{
	m_DrawManager.BoxErase(WIDTH, HEIGHT);
	m_DrawManager.DrawMidText("★ " + to_string(stage) + " Stage ★", WIDTH, HEIGHT* 0.5);
}

string Interface::AddString(string str, int count)
{
	string tmp;
	for (int i = 0; i < count; i++)
		tmp += str;
	return tmp;
}

KEY Interface::Typing(string &str, bool state)
{

	if (kbhit())
	{
		char ch = getch();
		switch (ch)
		{
		case KEY_BACKSPACE:
			str = str.substr(0, str.length() - 1);
			return KEY_BACKSPACE;
		case KEY_ENTER:
			return KEY_ENTER;
		default:
			if (state)
			{
				if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
					str += ch;
				return KEY_CHAR;
			}
		}
	}
	return KEY_NON;
}

void Interface::SetNameDraw()
{
	m_DrawManager.BoxErase(WIDTH, HEIGHT);
	m_DrawManager.DrawMidText("이름 입력", WIDTH, HEIGHT* 0.6);
	SmallBoxDraw();
}

void Interface::ScoreDraw(int score)
{
	SelectColor(COLOR_RED);
	m_DrawManager.DrawMidText("Score : " + to_string(score), m_ScorePos.m_ix, m_ScorePos.m_iy);
	ORIGINAL;
}

void Interface::LifeDraw(int life, int maxlife)
{
	string str;
	SelectColor(COLOR_RED);
	str += "Life : ";
	for (int i = 0; i < maxlife; i++)
	{
		if (i < life)
			str += "♥";
		else
			str += "  ";
	}
	m_DrawManager.TextDraw(str, m_LifePos.m_ix, m_LifePos.m_iy);
	ORIGINAL;
}

void Interface::EraseScore()
{
	m_DrawManager.DrawMidText("                       ", m_ScorePos.m_ix, m_ScorePos.m_iy);
}

void Interface::NameDraw(string name)
{
	SelectColor(COLOR_RED);
	m_DrawManager.DrawRightText("Name : " + name + AddString(" ", NAMESIZE - name.length()), m_NamePos.m_ix, m_NamePos.m_iy);
	ORIGINAL;
}

Interface::~Interface()
{
	delete[] m_strStoryList;
}
