#include<iostream>
using namespace std;
#pragma once

class Time
{
private:
	int m_iHour;
	int m_iMin;
public:
	void ShowTime();
	Time operator + (Time time);
	void Menu();
	Time();
	Time(int Hout, int Min);
	~Time();
};

