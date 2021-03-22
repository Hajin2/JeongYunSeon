#pragma once
#include"Macro.h"
#include"Interface.h"

#define LIFEMAX 9
#define NAMEMAX 10
#define WORDMAX 20
#define DONTTYPING 2000

class Player
{
private:
	const string m_strFailString;
	Interface m_Interface;
	string m_strName;
	int m_iLife;
	int m_iScore;
	int m_iFailClock;
	int m_iCurClock;
	string m_strCompareWord;
	bool m_bCompareState;
	bool m_bTypingState;

public:
	bool SetWord();
	void SetName();
	void Reset();
	KEY WordTyping(string& str, int limit);
	inline void ScoreReset() { m_iScore = 0; }
	inline string GetName() { return m_strName; }
	inline int GetLife() { return m_iLife; }
	inline int GetScore() { return m_iScore; }
	inline string GetWord() { return m_strCompareWord; }
	Player();
	~Player();
};

