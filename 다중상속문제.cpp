#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

class Person
{
protected:
	string m_strGender;
	int m_iAge;
	string m_strName;
public:
	void InputPerson()
	{
		cout << "나이 입력: ";
		cin >> m_iAge;
		cout << "이름 입력: ";
		cin >> m_strName;
		cout << "성별 입력: ";
		cin >> m_strGender;
	}
	void PrintPerson()
	{
		cout << "나이: " << m_iAge << endl;
		cout << "이름: " << m_strName << endl;
		cout << "성별: " << m_strGender << endl;
	}
};
class School
{
protected:
	int m_iGrade;
	int m_iGroup;
	int m_iNum;
public:
	void InputSchool()
	{
		cout << "학년 입력: ";
		cin >> m_iGrade;
		cout << "반 입력: ";
		cin >> m_iGroup;
		cout << "학생 번호 입력: ";
		cin >> m_iNum;
	}
	void PrintSchool()
	{
		cout << m_iGrade << "학년 " << m_iGroup << "반 " << m_iNum << "번 학생" << endl;
	}
};
class Student : public Person, public School
{
public:
	void Print()
	{
		InputSchool();
		InputPerson();
		system("cls");
		PrintSchool();
		PrintPerson();
	}
};
void main()
{
	Student st;
	st.Print();
}