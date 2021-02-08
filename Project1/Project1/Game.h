#pragma once
#include"Macro.h"
#include"MapDraw.h"
#include"Player.h"

enum MENU
{
	MENU_NEW = 1,
	MENU_LOAD,
	MENU_EXIT
};
class Game
{
protected:
	bool m_bPlayState;
	MapDraw m_MapDraw;
	Player m_Player;

public:
	Game();
	void Start();
	MENU Title();
	void InputName();
	void MainMenu();
	~Game();
};

