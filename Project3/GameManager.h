#pragma once
#include"Macro.h"
#include"Interface.h"
#include"Player.h"

#define NEXTSTAGEADDSCORE 1.2f
#define STAGEMAXSCORE 1000

class GameManager
{
private:
	Player m_Player;
	Interface m_Interface;
	string m_strName;
	int m_iStage;
	int m_iStageMaxScore;
	int m_iMaxScore;
	
public:
	void Title();
	void Draw();
	void Game();
	GameManager();
	~GameManager();
};