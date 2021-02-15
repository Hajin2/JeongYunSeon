#include "Game.h"

Game::Game()
{
	m_bPlayState = true;
}
void Game::Start()
{
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", HEIGHT + 1, 2 * WIDTH + 1);
	system(buf);
	while (1)
	{
		system("cls");
		BLUE;
		m_MapDraw.BoxDraw(0, 0, WIDTH, HEIGHT);
		TitleMenu();
		switch (m_MapDraw.MenuSelectCursor(3, 3, 10, 12))
		{
		case MENU_NEW:
			InputName();
			Main();
			break;
		case MENU_LOAD:
			break;
		case MENU_EXIT:
			return;
		}
	}
}
void Game::TitleMenu()
{
	RED;
	m_MapDraw.DrawMidText("�١� DeonGeonRPG �ڡ�", WIDTH, HEIGHT * 0.3f);
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
	m_MapDraw.TextDraw("PLAYER �̸� �Է�: ", WIDTH / 2, HEIGHT * 0.5f);
	cin >> Name;
	m_Player.InputName(Name);
}
void Game::MainMenu()
{
	RED;
	m_MapDraw.DrawMidText("�١� Menu �ڡ�", WIDTH, 8);
	m_MapDraw.DrawMidText("Deongeon", WIDTH, 10);
	m_MapDraw.DrawMidText("Player Info", WIDTH, 12);
	m_MapDraw.DrawMidText("Monster Info", WIDTH, 14);
	m_MapDraw.DrawMidText("Weapon Shop", WIDTH, 16);
	m_MapDraw.DrawMidText("Save", WIDTH, 18);
	m_MapDraw.DrawMidText("Exit", WIDTH, 20);
}
void Game::Main()
{
	Actor *player, *monster;
	int y = MAIN_GAME;
	while (1)
	{
		system("cls");
		BLUE;
		m_MapDraw.BoxDraw(0, 0, WIDTH, HEIGHT);
		MainMenu();
		switch (m_MapDraw.MenuSelectCursor(6, 2, 10, 10))
		{
		case MAIN_GAME:
			DeonGeon();
			break;
		case MAIN_PLAYER:
			player = new Player;
			player->ShowInfo();
			break;
		case MAIN_MONSTER:
			monster = new Monster;
			monster->ShowInfo();
			break;
		case MAIN_WEAPON:
			break;
		case MAIN_SAVE:
			break;
		case MAIN_EXIT:
			return;
		}
	}
}
void Game::DeonGeon()
{
	while (1)
	{
		system("cls");
		BLUE;
		m_MapDraw.BoxDraw(0, 0, WIDTH, HEIGHT);
		DeonGeonMenu();
		switch (m_MapDraw.MenuSelectCursor(7, 2, 6, 10))
		{
		case DG_GOBLIN:
			RPS();
			break;
		case DG_ORC:
			break;
		case DG_WOLF:
			break;
		case DG_OGRE:
			break;
		case DG_SKELETON:
			break;
		case DG_LICH:
			break;
		case DG_EXIT:
			return;
		}
	}
}
void Game::DeonGeonMenu()
{
	BLOOD;
	m_MapDraw.DrawMidText("=====���� �Ա�=====", WIDTH, 5);
	m_MapDraw.DrawMidText("1�� ����: [���]", WIDTH, 10);
	m_MapDraw.DrawMidText("2�� ����: [��ũ]", WIDTH, 12);
	m_MapDraw.DrawMidText("3�� ����: [�����ΰ�]", WIDTH, 14);
	m_MapDraw.DrawMidText("4�� ����: [�����]", WIDTH, 16);
	m_MapDraw.DrawMidText("5�� ����: [���̷����ó]", WIDTH, 18);
	m_MapDraw.DrawMidText("6�� ����: [��ġ]", WIDTH, 20);
	m_MapDraw.DrawMidText("���ư���", WIDTH, 22);
}
void Game::RPS()
{
	system("cls");
	BLUE;
	m_MapDraw.BoxDraw(0, 0, WIDTH, HEIGHT);
	RED;
	m_MapDraw.DrawMidText("--------------------------vs--------------------------", WIDTH, HEIGHT / 2);
	getch();
}
Game::~Game()
{
}
