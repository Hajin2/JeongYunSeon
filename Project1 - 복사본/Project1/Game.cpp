#include "Game.h"

Game::Game()
{
	m_Monster = NULL;
	m_Player = NULL;
	m_iMonsterCount = 0;
}
void Game::Start()
{
	srand(time(NULL));
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", HEIGHT + 1, 2 * WIDTH + 1);
	system(buf);
	while (1)
	{
		system("cls");
		BLUE
		m_MapDraw.BoxDraw(0, 0, WIDTH, HEIGHT);
		TitleMenu();
		switch (m_MapDraw.MenuSelectCursor(3, 3, 10, 12))
		{
		case MENU_NEW:
			if (Init(STARTTYPE_NEWSTART))
				Main();
			break;
		case MENU_LOAD:
			if (STARTTYPE_LOADSTART)
				Main();
			break;
		case MENU_EXIT:
			return;
		}
	}
}
bool Game::Init(STARTTYPE StartType)
{
	Delete();
	switch (StartType)
	{
	case STARTTYPE_NEWSTART:
		m_strPlayerFile = "DefaultPlayer.txt";
		m_strMonsterFile = "DefaultMonster.txt";
		break;
	case STARTTYPE_LOADSTART:
		if (!FileList(FS_LOAD))
			return false;
		break;
	}
	return Load(StartType);
}
void Game::TitleMenu()
{
	RED;
	m_MapDraw.DrawMidText("☆★ DeonJeonRPG ★☆", WIDTH, HEIGHT * 0.3f);
	m_MapDraw.DrawMidText("New Game", WIDTH, HEIGHT * 0.4f);
	m_MapDraw.DrawMidText("Load Game", WIDTH, HEIGHT * 0.5f);
	m_MapDraw.DrawMidText("Game Exit", WIDTH, HEIGHT * 0.6f);
}
void Game::MainMenu()
{
	RED;
	m_MapDraw.DrawMidText("☆★ Menu ★☆", WIDTH, 8);
	m_MapDraw.DrawMidText("DeonJeon", WIDTH, 10);
	m_MapDraw.DrawMidText("Player Info", WIDTH, 12);
	m_MapDraw.DrawMidText("Monster Info", WIDTH, 14);
	m_MapDraw.DrawMidText("Weapon Shop", WIDTH, 16);
	m_MapDraw.DrawMidText("Save", WIDTH, 18);
	m_MapDraw.DrawMidText("Exit", WIDTH, 20);
}
void Game::Main()
{
	while (1)
	{
		system("cls");
		BLUE;
		m_MapDraw.BoxDraw(0, 0, WIDTH, HEIGHT);
		MainMenu();
		int y;
		switch (m_MapDraw.MenuSelectCursor(6, 2, 10, 10))
		{
		case MAIN_GAME:
			DeonGeon();
			break;
		case MAIN_PLAYER:
			YELLOW
				m_MapDraw.BoxErase(WIDTH, HEIGHT);
			m_Player->ShowInfo(WIDTH - 15, HEIGHT * 0.5);
			ORIGINAL
				getch();
			break;
		case MAIN_MONSTER:
			m_MapDraw.BoxErase(WIDTH, HEIGHT);
			y = HEIGHT * 0.5 - (m_iMonsterCount / 2) * 4;
			for (int i = 0; i < m_iMonsterCount; i++)
				m_Monster[i].ShowInfo(WIDTH - 15, y + i * 4);
			getch();
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
		BLUE
		m_MapDraw.BoxDraw(0, 0, WIDTH, HEIGHT);
		DeonGeonMenu();
		int Select = m_MapDraw.MenuSelectCursor(7, 2, 6, 10);
		if (Select == m_iMonsterCount + 1)
			return;
		else if (Select >= 1 && Select <= m_iMonsterCount)
			Fight(m_Player, &m_Monster[Select - 1]);
	}
}
void Game::Fight(Character* Player, Character* Monster)
{
	/*bool GameEnd = false;
	RSP PlayerRsp, MonsterRsp;
	m_DrawManager.BoxErase(WIDTH, HEIGHT);
	while (1)
	{
		YELLOW
			Player->ShowInfo(WIDTH - 15, HEIGHT * 0.1);
		m_DrawManager.DrawMidText("가위 : 1   바위 : 2   보 : 3", WIDTH, HEIGHT*0.3);
		ORIGINAL
			Monster->ShowInfo(WIDTH - 15, HEIGHT * 0.8);
		RED
			m_DrawManager.DrawMidText("-------------------------- vs --------------------------", WIDTH, HEIGHT*0.5);
		if (Player->GetHealth() == 0)
		{
			if (!Monster->ExpUp(*Player))
				m_bGameExit = true;
			return;
		}
		else if (Monster->GetHealth() == 0)
		{
			Player->ExpUp(*Monster);
			return;
		}
		PlayerRsp = Player->GetRSP();
		m_DrawManager.BoxErase(WIDTH, HEIGHT);
		YELLOW
			RSPDraw(PlayerRsp, WIDTH, HEIGHT*0.4);
		MonsterRsp = Monster->GetRSP();
		ORIGINAL
			RSPDraw(MonsterRsp, WIDTH, HEIGHT*0.65);
		RED
			if (PlayerRsp > MonsterRsp)
			{
				if (PlayerRsp == RSP_PAPER && MonsterRsp == RSP_SCISSOR)
				{
					m_DrawManager.DrawMidText("Win", WIDTH, HEIGHT*0.6);
					m_DrawManager.DrawMidText("Lose", WIDTH, HEIGHT*0.45);
					Monster->Attack(Player);
				}
				else
				{
					m_DrawManager.DrawMidText("Win", WIDTH, HEIGHT*0.45);
					m_DrawManager.DrawMidText("Lose", WIDTH, HEIGHT*0.6);
					Player->Attack(Monster);
				}
			}
			else if (PlayerRsp < MonsterRsp)
			{
				if (PlayerRsp == RSP_SCISSOR && MonsterRsp == RSP_PAPER)
				{
					m_DrawManager.DrawMidText("Win", WIDTH, HEIGHT*0.45);
					m_DrawManager.DrawMidText("Lose", WIDTH, HEIGHT*0.6);
					Player->Attack(Monster);
				}
				else
				{
					m_DrawManager.DrawMidText("Win", WIDTH, HEIGHT*0.6);
					m_DrawManager.DrawMidText("Lose", WIDTH, HEIGHT*0.45);
					Monster->Attack(Player);
				}
			}
			else
			{
				m_DrawManager.DrawMidText("Draw", WIDTH, HEIGHT*0.45);
				m_DrawManager.DrawMidText("Draw", WIDTH, HEIGHT*0.6);
			}
		ORIGINAL

	}*/
}
void Game::DeonGeonMenu()
{
	BLOOD
	m_MapDraw.DrawMidText("=====던전 입구=====", WIDTH, 5);
	m_MapDraw.DrawMidText("1층 던전: [고블린]", WIDTH, 10);
	m_MapDraw.DrawMidText("2층 던전: [오크]", WIDTH, 12);
	m_MapDraw.DrawMidText("3층 던전: [늑대인간]", WIDTH, 14);
	m_MapDraw.DrawMidText("4층 던전: [오우거]", WIDTH, 16);
	m_MapDraw.DrawMidText("5층 던전: [스켈레톤아처]", WIDTH, 18);
	m_MapDraw.DrawMidText("6층 던전: [리치]", WIDTH, 20);
	m_MapDraw.DrawMidText("돌아가기", WIDTH, 22);
}
bool Game::Load(STARTTYPE StartType)
{
	m_MapDraw.BoxErase(WIDTH, HEIGHT);
	ifstream Load;
	Load.open(m_strPlayerFile);
	if (!Load.is_open())
	{
		cout << "Player정보 없음" << endl;
		return false;
	}
	m_Player = new Character;
	m_Player->SetInfo(Load, CH_PLAYER, StartType);
	Load.close();
	Load.open(m_strMonsterFile);
	if (!Load.is_open())
	{
		cout << "Monster정보 없음" << endl;
		return false;
	}
	Load >> m_iMonsterCount;
	m_Monster = new Character[m_iMonsterCount];
	for (int i = 0; i < m_iMonsterCount; i++)
		m_Monster[i].SetInfo(Load, CH_MONSTER, StartType);
	Load.close();
	return true;
}
bool Game::FileList(FILESTATE State)
{
	return false;
}
void Game::Delete()
{
	if (m_Monster)
		delete[] m_Monster;
	if (m_Player)
		delete m_Player;
}
Game::~Game()
{
}
