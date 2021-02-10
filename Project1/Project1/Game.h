#pragma once
#include"Macro.h"
#include"MapDraw.h"
#include"Actor.h"
#include"Player.h"
#include"Monster.h"

enum MENU
{
	MENU_NEW = 1,
	MENU_LOAD,
	MENU_EXIT
};
enum MAIN
{
	MAIN_GAME = 10,
	MAIN_PLAYER = 12,
	MAIN_MONSTER = 14,
	MAIN_WEAPON = 16,
	MAIN_SAVE = 18,
	MAIN_EXIT = 20
};

class Game
{
protected:
	bool m_bPlayState;
	MapDraw m_MapDraw;
	Player m_Player;
	Actor* m_Actor;

public:
	Game();
	void Start();
	void TitleMenu();
	void InputName();
	void MainMenu();
	void Main();
	~Game();
};

