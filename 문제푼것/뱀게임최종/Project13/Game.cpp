#include "Game.h"

Game::Game()
{
	m_bPlayState = false;
	m_iScore = 0;
}
void Game::Start()
{
	int menu;
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", HEIGHT + 3, 2 * WIDTH + 1);
	system(buf);
	m_MapDraw.BoxDraw();
	Title();
	cin >> menu;
	switch (menu)
	{
	case MENU_START:
		m_bPlayState = true;
		MainGame();
		break;
	case MENU_END:
		return;
	}
}
void Game::Title()
{
	m_MapDraw.DrawMidText("★ ☆ ★ Snake Game ★ ☆ ★", WIDTH, HEIGHT * 0.3f);
	m_MapDraw.DrawMidText("1. 게임 시작", WIDTH, HEIGHT * 0.4f);
	m_MapDraw.DrawMidText("2. 게임 종료", WIDTH, HEIGHT * 0.5f);
	m_MapDraw.DrawMidText("선택: ", WIDTH, HEIGHT * 0.6f);
}
void Game::PrintScore()
{
	string str = "Score: " + to_string(m_iScore);
	m_MapDraw.DrawMidText(str, WIDTH, HEIGHT + 2);
}
void Game::MainGame()
{
	system("cls");
	m_MapDraw.BoxDraw();
	m_BlockManager.MakeObstacle();
	m_Snake.SetSnake();
	m_Snake.Draw();
	PrintScore();
	while (m_bPlayState == true)
	{
		m_BlockManager.MakeFeed(m_Snake.GetHead(), m_Snake.GetTail());
		m_Snake.Key();
		m_Snake.Move();
		EatFeed();
		Crash();
	}
}
void Game::EatFeed()
{
	if (m_BlockManager.EatFeed(m_Snake.GetHead()) == true)
	{
		m_iScore++;
		m_Snake.AddTail();
		m_Snake.SpeedUp();
		PrintScore();
	}
}
void Game::Crash()
{
	if (m_BlockManager.CrashObs(m_Snake.GetHead()) || m_Snake.CrashWall() || m_Snake.CrashTail())
	{
		m_bPlayState = false;
		GameOver();
	}
}
void Game::GameOver()
{
	system("cls");
	m_MapDraw.BoxDraw();
	m_MapDraw.DrawMidText("★ ☆ ★ Game Over ★ ☆ ★", WIDTH, HEIGHT * 0.4f);
	m_MapDraw.DrawMidText("Continue: Space Bar", WIDTH, HEIGHT * 0.5f);
	PrintScore();
	char key = getch();
	switch (key)
	{
	case SPACEBAR:
		m_BlockManager.ClearFeed();
		m_BlockManager.ClearObs();
		m_Snake.ClearSnake();
		m_iScore = 0;
		Start();
		break;
	default:
		break;
	}
}