#include "Snake.h"

Snake::Snake()
{
	m_iMoveClock = clock();
}
void Snake::SetSnake()
{
	m_iMoveSpeed = 300;
	m_bLiveState = true;
	m_eDirection = DIRECTION_NON;
	m_SnakeHead.m_ix = WIDTH / 2;
	m_SnakeHead.m_iy = HEIGHT / 2;
}
void Snake::Move() //±ôºýÀÓ °³¼± - ¸¶Áö¸· ²¿¸®¸¸ Áö¿öÁö°Ô
{
	int CurClock = clock();
	if (m_bLiveState == true && CurClock - m_iMoveClock > m_iMoveSpeed)
	{
		Erase();
		switch (m_eDirection)
		{
		case DIRECTION_NON:
			break;
		case DIRECTION_LEFT:
			MoveHead(WAY_WIDTH, -1);
			break;
		case DIRECTION_RIGHT:
			MoveHead(WAY_WIDTH, 1);
			break;
		case DIRECTION_UP:
			MoveHead(WAY_HEIGHT, -1);
			break;
		case DIRECTION_DOWN:
			MoveHead(WAY_HEIGHT, 1);
			break;
		}
		if(m_SnakeTail.empty() == false)
			MoveTail(m_LastPos, 0);
		Draw();
		m_iMoveClock = CurClock;
	}
}
void Snake::MoveHead(int way, int direction)
{
	SaveLastPos();
	if (way == WAY_WIDTH)
		m_SnakeHead.m_ix += direction;
	else if(way == WAY_HEIGHT)
		m_SnakeHead.m_iy += direction;
}
void Snake::Draw()
{
	m_MapDraw.DrawPoint(HEAD, m_SnakeHead.m_ix, m_SnakeHead.m_iy);
	for (auto iter = m_SnakeTail.begin(); iter != m_SnakeTail.end(); iter++)
		m_MapDraw.DrawPoint(TAIL, iter->m_ix, iter->m_iy);
}
void Snake::Erase()
{
	m_MapDraw.ErasePoint(m_SnakeHead.m_ix, m_SnakeHead.m_iy);
	if(m_SnakeTail.empty() == false)
		m_MapDraw.ErasePoint(m_SnakeTail.back().m_ix, m_SnakeTail.back().m_iy);
}
void Snake::MoveTail(Position pos, int count)
{
	if (m_SnakeTail.size() == count)
		return;
	Position tmp;
	tmp = m_SnakeTail.at(count);
	m_SnakeTail.at(count) = pos;
	MoveTail(tmp, ++count);
}
void Snake::Key()
{
	char key;
	if (kbhit())
	{
		key = getch();
		switch (key)
		{
		case LEFT:
			if (m_eDirection != DIRECTION_RIGHT)
				m_eDirection = DIRECTION_LEFT;
			break;
		case RIGHT:
			if (m_eDirection != DIRECTION_LEFT)
				m_eDirection = DIRECTION_RIGHT;
			break;
		case UP:
			if (m_eDirection != DIRECTION_DOWN)
				m_eDirection = DIRECTION_UP;
			break;
		case DOWN:
			if (m_eDirection != DIRECTION_UP)
				m_eDirection = DIRECTION_DOWN;
			break;
		default:
			break;
		}
	}
}
void Snake::AddTail()
{
	if (m_SnakeTail.empty() == true)
		m_SnakeTail.push_back(m_LastPos);
	else
		m_SnakeTail.push_back(m_SnakeTail.back());
}
bool Snake::CrashTail()
{
	for (auto iter = m_SnakeTail.begin(); iter != m_SnakeTail.end(); iter++)
	{
		if (m_SnakeHead.m_ix == iter->m_ix && m_SnakeHead.m_iy == iter->m_iy)
			return true;
	}
	return false;
}
bool Snake::CrashWall()
{
	if (m_SnakeHead.m_ix == 0 || m_SnakeHead.m_ix == WIDTH - 1
		|| m_SnakeHead.m_iy == 0 || m_SnakeHead.m_iy == HEIGHT - 1)
		return true;
	return false;
}