#include "BlockManager.h"

BlockManager::BlockManager()
{
	m_iFeedClock = clock();
	m_iFeedNum = 0;
}
void BlockManager::MakeObstacle()
{
	for (int y = 1; y < HEIGHT-1; y++)
	{
		for (int x = 1; x < WIDTH-1; x++)
		{
			if (x == WIDTH / 2 && y == HEIGHT / 2)
				break;
			if (rand() % OBS_PERCENT == BLOCK_OBS)
			{
				m_Position.m_ix = x;
				m_Position.m_iy = y;
				m_ObsList.push_back(m_Position);
				m_MapDraw.DrawPoint(OBSTACLE, x, y);
			}
			else
				m_MapDraw.DrawPoint("  ", x, y);
		}
	}
}
void BlockManager::MakeFeed(Position Pos, vector <Position> vPos) //赣府, 部府俊 积己 救登霸
{
	int CurClock = clock();
	if (m_FeedList.size() < FEEDMAX && CurClock - m_iFeedClock > TIME_FEED)
	{
		Position FeedPos;
		FeedPos.m_ix = rand() % (WIDTH - 2) + 1;
		FeedPos.m_iy = rand() % (HEIGHT - 2) + 1;
		if (Pos.m_ix == FeedPos.m_ix && Pos.m_iy == FeedPos.m_iy)
			return;
		for (auto iter = m_ObsList.begin(); iter != m_ObsList.end(); iter++)
		{
			if (iter->m_ix == FeedPos.m_ix && iter->m_iy == FeedPos.m_iy)
				return;
		}
		for (auto iter_1 = vPos.begin(); iter_1 != vPos.end(); iter_1++)
		{
			if (iter_1->m_ix == FeedPos.m_ix && iter_1->m_ix == FeedPos.m_iy)
				return;
		}
		m_FeedList.push_back(FeedPos);
		m_MapDraw.DrawPoint(FEED, FeedPos.m_ix, FeedPos.m_iy);
		m_iFeedClock = CurClock;
	}
}
bool BlockManager::EatFeed(Position pos)
{
	for (auto iter = m_FeedList.begin(); iter != m_FeedList.end(); iter++)
	{
		if (iter->m_ix == pos.m_ix && iter->m_iy == pos.m_iy)
		{
			m_FeedList.erase(iter);
			return true;
		}
	}
	return false;
}
bool BlockManager::CrashObs(Position pos)
{
	for (auto iter = m_ObsList.begin(); iter != m_ObsList.end(); iter++)
	{
		if (iter->m_ix == pos.m_ix && iter->m_iy == pos.m_iy)
		{
			return true;
		}
	}
	return false;
}