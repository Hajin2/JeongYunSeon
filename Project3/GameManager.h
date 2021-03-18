#pragma once
#include"Macro.h"
#include"Interface.h"

#define NEXTSTAGEADDSCORE 1.2f
#define STAGEMAXSCORE 1000

class GameManager
{
private:
	Interface m_Interface;
	string m_strName;
	int m_iStage;
	int m_iStageMaxScore;
	int m_iMaxScore;
	
public:
	void Title();
	void Draw();
	GameManager();
	~GameManager();
};