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
		switch (m_Interface.GetDrawManager().MenuSelectCursor(3, 3, (WIDTH / 2) - (sizeof("1.Game Start") / 2), HEIGHT*0.4))
		{
		case 1:
			Draw();
			m_Interface.StoryDraw();
			m_Player.SetName();
			Game();
			break;
		case 2:
			break;
		case 3:
			return;
		}
	}
}

void GameManager::Draw()
{
	system("cls");
	m_Interface.BoxDraw(COLOR_BLUE_GREEN);
	m_Interface.LifeDraw(m_Player.GetLife(), LIFEMAX);
	m_Interface.EraseScore();
	m_Interface.ScoreDraw(m_Player.GetScore());
	m_Interface.NameDraw(m_Player.GetName());
}

void GameManager::Game()
{
	BLUE;
	while (m_iStage <= 6)
	{
		m_Interface.StageDraw(m_iStage);
		Sleep(1000);
		m_Interface.GetDrawManager().BoxErase(WIDTH, HEIGHT);
		m_Interface.SmallBoxDraw();
		while (1)
		{
			BLUE;
			if (m_Player.SetWord())
			{
			}
		}
	}
}

GameManager::~GameManager()
{
}
