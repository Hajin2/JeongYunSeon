#pragma once
#include"Macro.h"
#include"MapDraw.h"
#include"BlockManager.h"
#include"Snake.h"

class Game
{
private:
	MapDraw m_MapDraw;
	BlockManager m_BlockManager;
	Snake m_Snake;
	bool m_bPlayState;
	int m_iScore;

public:
	Game();
	void Start();
	void Title();
	void MainGame();
	void PrintScore();
	void EatFeed();
	void Crash();
	void GameOver();
};

