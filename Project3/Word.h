#pragma once
#include"Macro.h"
#include"Interface.h"

enum ITEM
{
	ITEM_BLIND,
	ITEM_SPEED_UP,
	ITEM_SPEED_DOWN,
	ITEM_STOP,
	ITEM_CLEAR,
	ITEM_END,
	ITEM_NON
};

enum WORDSTATE
{
	WS_WAIT,
	WS_DROP,
	WS_DIE
};

class Word
{
private:
	int m_ix;
	int m_iy;
	ITEM m_eItemState;
	Interface m_Interface;
	string m_strWord;
	WORDSTATE m_eWordState;
	bool m_bHideState;
	void LeftErase(bool BlindState, bool State = true);
	void RightErase(bool BlindState, bool State = true);
public:
	inline ITEM GetItem() { return m_eItemState; }
	Word();
	~Word();
};

