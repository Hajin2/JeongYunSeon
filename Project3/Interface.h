#pragma once
#include"Macro.h"
#include"MapDraw.h"

#define FILENAME "베네치아_스토리.txt"
#define STORYTIME 500
#define BACKSPACE 8
#define ENTER 13

enum COLOR
{
	COLOR_BLACK,
	COLOR_DARK_BLUE,
	COLOR_GREEN,
	COLOR_BLUE_GREEN,
	COLOR_BLOOD,
	COLOR_PUPPLE,
	COLOR_GOLD,
	COLOR_ORIGINAL,
	COLOR_GRAY,
	COLOR_BLUE,
	COLOR_HIGH_GREEN,
	COLOR_SKY_BLUE,
	COLOR_RED,
	COLOR_PLUM,
	COLOR_YELLOW
};

struct Point
{
	int m_ix, m_iy;
};

enum KEY
{
	KEY_CHAR,
	KEY_NON,
	KEY_BACKSPACE = 8,
	KEY_ENTER = 13,

};

class Interface
{
private:
	MapDraw m_DrawManager;
	Point m_LifePos;
	Point m_ScorePos;
	Point m_NamePos;
	string* m_strStoryList;
	int m_iStoryLineCount;
	
public:
	Interface();
	void SelectColor(COLOR color);
	void BoxDraw(COLOR color);
	void SmallBoxDraw(string str = "");
	void StoryDraw();
	void TitleDraw();
	void StageDraw(int stage);
	string AddString(string str, int count);
	KEY Typing(string &str, bool state);
	void SetNameDraw();
	void ScoreDraw(int score);
	void LifeDraw(int life, int maxlife);
	void NameDraw(string name);
	void EraseScore();
	inline MapDraw GetDrawManager()
	{
		return m_DrawManager;
	}
	~Interface();
};

