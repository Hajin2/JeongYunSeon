#include "Game.h"

Game::Game()
{
	m_bPlayState = true;
}
void Game::Start()
{
	int y = HEIGHT * 0.4f;
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", HEIGHT + 1, 2 * WIDTH + 1);
	system(buf);
	while (1)
	{
		system("cls");
		BLUE;
		m_MapDraw.BoxDraw(0, 0, WIDTH, HEIGHT);
		TitleMenu();
		m_MapDraw.TextDraw("▷", 22, y);
		char key = getch();
		switch (key)
		{
		case UP:
			m_MapDraw.ErasePoint((WIDTH - 8) / 2, y);
			if (y == HEIGHT * 0.4f)
				m_MapDraw.TextDraw("▷", WIDTH - 8, y += 6);
			else
				m_MapDraw.TextDraw("▷", WIDTH - 8, y -= 3);
			break;
		case DOWN:
			m_MapDraw.ErasePoint((WIDTH - 8) / 2, y);
			if (y == HEIGHT * 0.6f)
				m_MapDraw.TextDraw("▷", WIDTH - 8, y -= 6);
			else
				m_MapDraw.TextDraw("▷", WIDTH - 8, y += 3);
			break;
		case ENTER:
			if (y == HEIGHT * 0.4f)
			{
				InputName();
				Main();
				break;
			}
			else if (y == HEIGHT * 0.5f)
				break;
			else
				return;
		}
	}
}
void Game::TitleMenu()
{
	RED;
	m_MapDraw.DrawMidText("☆★ DeonGeonRPG ★☆", WIDTH, HEIGHT * 0.3f);
	m_MapDraw.DrawMidText("New Game", WIDTH, HEIGHT * 0.4f);
	m_MapDraw.DrawMidText("Load Game", WIDTH, HEIGHT * 0.5f);
	m_MapDraw.DrawMidText("Game Exit", WIDTH, HEIGHT * 0.6f);
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
}
void Game::MainMenu()
{
	RED;
	m_MapDraw.DrawMidText("☆★ Menu ★☆", WIDTH, 8);
	m_MapDraw.DrawMidText("Deongeon", WIDTH, MAIN_GAME);
	m_MapDraw.DrawMidText("Player Info", WIDTH, MAIN_PLAYER);
	m_MapDraw.DrawMidText("Monster Info", WIDTH, MAIN_MONSTER);
	m_MapDraw.DrawMidText("Weapon Shop", WIDTH, MAIN_WEAPON);
	m_MapDraw.DrawMidText("Save", WIDTH, MAIN_SAVE);
	m_MapDraw.DrawMidText("Exit", WIDTH, MAIN_EXIT);
}
void Game::Main()
{
	int y = MAIN_GAME;
	while (1)
	{
		system("cls");
		BLUE;
		m_MapDraw.BoxDraw(0, 0, WIDTH, HEIGHT);
		MainMenu();
		m_MapDraw.TextDraw("▷", 20, y);
		char key = getch();
		switch (key)
		{
		case UP:
			m_MapDraw.ErasePoint(20 / 2, y);
			if (y == MAIN_GAME)
				m_MapDraw.TextDraw("▷", 20, y += 10);
			else
				m_MapDraw.TextDraw("▷", 20, y -= 2);
			break;
		case DOWN:
			m_MapDraw.ErasePoint(20 / 2, y);
			if (y == MAIN_EXIT)
				m_MapDraw.TextDraw("▷", 20, y -= 10);
			else
				m_MapDraw.TextDraw("▷", 20, y += 2);
			break;
		case ENTER:
			if (y == MAIN_GAME)
				break;
			else if (y == MAIN_PLAYER)
			{
				m_Player.ShowInfo();
				break;
			}
			else if (y == MAIN_MONSTER)
			{
				break;
			}
			else if (y == MAIN_WEAPON)
				break;
			else if (y == MAIN_SAVE)
				break;
			else if (y == MAIN_EXIT)
				return;
		}
	}
}
Game::~Game()
{
}
