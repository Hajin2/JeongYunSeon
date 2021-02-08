#pragma once
#include"Macro.h"
#include"MapDraw.h"

#define LEFT 'a'
#define RIGHT 'd'
#define UP 'w'
#define DOWN 's'

enum DIRECTION
{
	DIRECTION_NON,
	DIRECTION_LEFT,
	DIRECTION_RIGHT,
	DIRECTION_UP,
	DIRECTION_DOWN
};

enum WAY
{
	WAY_WIDTH,
	WAY_HEIGHT
};

class Snake
{
private:
	Position m_LastPos;
	Position m_SnakeHead;
	vector <Position> m_SnakeTail;
	MapDraw m_MapDraw;
	DIRECTION m_eDirection;
	bool m_bLiveState;
	int m_iMoveClock;
	int m_iMoveSpeed;

public:
	Snake();
	void SetSnake();
	void Draw();
	void Erase();
	void Move();
	void MoveTail(Position pos, int count);
	void MoveHead(int way, int direction);
	void Key();
	void AddTail();
	bool CrashTail();
	bool CrashWall();
	inline void SaveLastPos()
	{
		m_LastPos = m_SnakeHead;
	}
	inline Position GetHead()
	{
		return m_SnakeHead;
	}
	inline vector <Position> GetTail()
	{
		return m_SnakeTail;
	}
	inline void ClearSnake()
	{
		m_SnakeTail.clear();
	}
	inline void SpeedUp()
	{
		if (m_iMoveSpeed > 50)
			m_iMoveSpeed -= 10;
	}
};

