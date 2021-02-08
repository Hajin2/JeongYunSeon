#pragma once
#include"Macro.h"
#include"MapDraw.h"

class BlockManager
{
private:
	MapDraw m_MapDraw;
	int m_iFeedClock;
	int m_iFeedNum;
	Position m_Position;
	vector <Position> m_ObsList;
	vector <Position> m_FeedList;

public:
	BlockManager();
	void MakeObstacle();
	void MakeFeed(Position Pos, vector <Position> pos);
	bool EatFeed(Position pos);
	bool CrashObs(Position pos);
	inline void ClearObs()
	{
		m_ObsList.clear();
	}
	inline void ClearFeed()
	{
		m_FeedList.clear();
	}
};

