#include "Time.h"

void Time::ShowTime()
{
	cout << "�� ���� �ð�: " << m_iHour << " : " << m_iMin << endl;
}
Time Time::operator + (Time time)
{
	this->m_iHour = time.m_iHour + this->m_iHour;
	this->m_iMin = time.m_iMin + this->m_iMin;
	return *this;
}
void Time::Menu()
{
	Time add(0, 0);
	int day = 1;
	int menu;
	while (1)
	{
		system("cls");
		ShowTime();
		cout << "====���� �ð� ���� ���α׷�(" << day << "Day)====" << endl;
		cout << "\t1. �ð� ���" << endl;
		cout << "\t2. ����" << endl;
		cout << "\t�Է�: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "�ð�: ";
			cin >> add.m_iHour;
			cout << "��: ";
			cin >> add.m_iMin;
			*this = *this + add;
			day++;
			break;
		case 2:
			system("cls");
			ShowTime();
			return;
		}
	}
}
Time::Time()
{
	m_iHour = 0;
	m_iMin = 0;
}
Time::Time(int Hour, int Min)
{
	m_iHour = Hour;
	m_iMin = Min;
}
Time::~Time()
{

}