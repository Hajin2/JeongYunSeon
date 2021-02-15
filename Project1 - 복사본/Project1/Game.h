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
	MAIN_GAME = 1,
	MAIN_PLAYER,
	MAIN_MONSTER,
	MAIN_WEAPON,
	MAIN_SAVE,
	MAIN_EXIT
};
enum DG
{
	DG_GOBLIN = 1,
	DG_ORC,
	DG_WOLF,
	DG_OGRE,
	DG_SKELETON,
	DG_LICH,
	DG_EXIT
};
class Game
{
protected:
	bool m_bPlayState;
	MapDraw m_MapDraw;
	Player m_Player;
	Monster m_Monster;
	Actor* m_Actor;

public:
	Game();
	void Start();
	void TitleMenu();
	void InputName();
	void MainMenu();
	void Main();
	void DeonGeon();
	void DeonGeonMenu();
	void RPS();
	~Game();
};

