#include "Game.h"



Game::Game()
{
	m_bPlayState = true;
}
void Game::Start()
{
	int menu;
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", HEIGHT + 1, 2 * WIDTH + 1);
	system(buf);
	BLUE;
	m_MapDraw.BoxDraw(0, 0, WIDTH, HEIGHT);
	switch (Title())
	{
	case MENU_NEW:
		InputName();
		break;
	case MENU_LOAD:
		break;
	case MENU_EXIT:
		return;
	}

}
MENU Game::Title()
{
	RED;
	int y = HEIGHT * 0.4f;
	m_MapDraw.DrawMidText("☆★ DeonGeonRPG ★☆", WIDTH, HEIGHT * 0.3f);
	m_MapDraw.DrawMidText("New Game", WIDTH, HEIGHT * 0.4f);
	m_MapDraw.DrawMidText("Load Game", WIDTH, HEIGHT * 0.5f);
	m_MapDraw.DrawMidText("Game Exit", WIDTH, HEIGHT * 0.6f);
	m_MapDraw.TextDraw("▷", WIDTH - 8, y);
	while (1)
	{
		char key = getch();
		switch (key)
		{
		case UP:
			m_MapDraw.ErasePoint(WIDTH / 2 - 4, y);
			if (y == HEIGHT * 0.4f)
				m_MapDraw.TextDraw("▷", WIDTH - 8, y += 6);
			else
				m_MapDraw.TextDraw("▷", WIDTH - 8, y -= 3);
			break;
		case DOWN:
			m_MapDraw.ErasePoint(WIDTH / 2 - 4, y);
			if (y == HEIGHT * 0.6f)
				m_MapDraw.TextDraw("▷", WIDTH - 8, y -= 6);
			else
				m_MapDraw.TextDraw("▷", WIDTH - 8, y += 3);
			break;
		case ENTER:
			if (y == HEIGHT * 0.4f)
				return MENU_NEW;
			else if (y == HEIGHT * 0.5f)
				return MENU_LOAD;
			else
				return MENU_EXIT;
		}
	}
}
void Game::InputName()
{
	string Name;
	system("cls");
	BLUE;
	m_MapDraw.BoxDraw(0, 0, WIDTH, HEIGHT);
	YELLOW;
	m_MapDraw.TextDraw("PLAYER 이름 입력: ", WIDTH / 2, HEIGHT * 0.5f);
	cin >> Name;
	m_Player.InputName(Name);
	MainMenu();
}
void Game::MainMenu() //맞게 수정
{
	RED;
	int y = HEIGHT * 0.4f;
	m_MapDraw.DrawMidText("☆★ DeonGeonRPG ★☆", WIDTH, HEIGHT * 0.3f);
	m_MapDraw.DrawMidText("New Game", WIDTH, HEIGHT * 0.4f);
	m_MapDraw.DrawMidText("Load Game", WIDTH, HEIGHT * 0.5f);
	m_MapDraw.DrawMidText("Game Exit", WIDTH, HEIGHT * 0.6f);
	m_MapDraw.TextDraw("▷", WIDTH - 8, y);
}
Game::~Game()
{
}
