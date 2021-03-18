#include "GameManager.h"

GameManager::GameManager()
{
	m_iStageMaxScore = STAGEMAXSCORE;
	m_iStage = 1;
}

void GameManager::Title()
{
	srand(time(NULL));
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", HEIGHT + 4, 2 * WIDTH);
	system(buf);
	while (1)
	{
		Draw();
		m_Interface.TitleDraw();
	}
}

void GameManager::Draw()
{
	system("cls");
	m_Interface.BoxDraw(COLOR_BLUE_GREEN);
}

GameManager::~GameManager()
{
}
