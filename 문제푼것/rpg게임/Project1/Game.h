#pragma once
#include"Macro.h"
#include"MapDraw.h"
#include"Character.h"
#include"Shop.h"

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
enum FILESTATE
{
	FS_SAVE,
	FS_LOAD
};
class Game
{
private:
	MapDraw m_MapDraw;
	Character *m_Monster;
	Character *m_Player;
	string m_strPlayerFile;
	string m_strMonsterFile;
	Shop m_Shop;
	int m_iMonsterCount;
	bool m_bGameExit;
public:
	Game();
	void Start();
	bool Init(STARTTYPE StartType);
	void TitleMenu();
	void MainMenu();
	void Main();
	void DeonGeon();
	void DeonGeonMenu();
	void Fight(Character* Player, Character* Monster);
	void RPSDraw(RPS rps, int x, int y);
	void Delete();
	void Save();
	bool Load(STARTTYPE StartType);
	bool FileList(FILESTATE State);
	~Game();
};

