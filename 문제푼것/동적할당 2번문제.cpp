#include<iostream>
#include<string>
#include<Windows.h>
#include<vector>
using namespace std;

#define MAX 10

struct student
{
	string name;
	int age;
	int year;
	int num;
	int kor;
	int eng;
	int math;
	int sum;
	double avr;
	char grade;
};
vector<student*> regist(vector<student*> st)
{
	student *tmp = new student;
	system("cls");
	tmp->num = st.size() + 1;
	cout << "======" << tmp->num << "��° �л�======" << endl;
	cout << "�̸�: ";
	cin >> tmp->name;
	cout << "����: ";
	cin >> tmp->age;
	while (1)
	{
		cout << "�г�(1~3): ";
		cin >> tmp->year;
		if (tmp->year >= 1 && tmp->year <= 3)
			break;
		cout << "�߸� �Է� �ٽ�" << endl;
	}
	cout << "���� ����: ";
	cin >> tmp->kor;
	cout << "���� ����: ";
	cin >> tmp->eng;
	cout << "���� ����: ";
	cin >> tmp->math;
	tmp->sum = tmp->kor + tmp->eng + tmp->math;
	tmp->avr = tmp->sum / 3.0;
	if (tmp->avr >= 90)
		tmp->grade = 'A';
	else if (tmp->avr >= 80)
		tmp->grade = 'B';
	else if (tmp->avr >= 70)
		tmp->grade = 'C';
	else if (tmp->avr >= 60)
		tmp->grade = 'D';
	else
		tmp->grade = 'F';
	st.push_back(tmp);
	system("pause");
	return st;
}
void show(vector<student*>::iterator iter)
{
	cout << "=======" << (*iter)->num << "��° �л�======" << endl;
	cout << "�̸�: " << (*iter)->name << endl;
	cout << "����: " << (*iter)->age << "��" << endl;
	cout << "�г�: " << (*iter)->year << "�г�" << endl;
	cout << "���� ����: " << (*iter)->kor << endl;
	cout << "���� ����: " << (*iter)->eng << endl;
	cout << "���� ����: " << (*iter)->math << endl;
	cout << "�հ� ����: " << (*iter)->sum << "\t��� ����: " << (*iter)->avr << endl;
	cout << "���: [" << (*iter)->grade << "]" << endl << endl;
}
void search(vector<student*> st)
{
	vector<student*>::iterator iter;
	string tmp_name;
	cout << "�̸� �Է�: ";
	cin >> tmp_name;
	for (iter = st.begin(); iter != st.end(); iter++)
	{
		if (tmp_name == (*iter)->name)
		{
			show(iter);
			return;
		}
	}
	if (iter == st.end())
		cout << "�ش� �л��� �����ϴ�." << endl;
}
void release(vector<student*> st)
{
	for (auto iter = st.begin(); iter != st.end(); iter++)
	{
		cout << (*iter)->num << "�� �л�: " << (*iter)->name << endl;
		delete *iter;
		cout << "�Ҵ� ���� �Ϸ�" << endl;
	}
}
void showyear(vector<student*>st, int year)
{
	cout << "��������������������" << year << "�г⦡������������������" << endl;
	for (auto iter = st.begin(); iter != st.end(); iter++)
	{
		if ((*iter)->year == year)
			show(iter);
	}
	cout << "����������������������������������������������" << endl;
}
void showgrade(vector<student*> st, char grade)
{
	cout << "��������������������" << grade << "��ަ�������������������" << endl;
	for (auto iter = st.begin(); iter != st.end(); iter++)
	{
		if ((*iter)->grade == grade)
			show(iter);
	}
	cout << "����������������������������������������������" << endl;
}
void main()
{
	vector <student*> st;
	int select = 0;
	while (1)
	{
		system("cls");
		cout << "===�л� ���� ����===(�л���: " << st.size() << "��)" << endl;
		cout << "1. �л� ���" << endl;
		cout << "2. �л� ���� ����" << endl;
		cout << "3. �л� �˻�" << endl;
		cout << "4. ��޺� ����" << endl;
		cout << "5. �г⺰ ����" << endl;
		cout << "6. ����" << endl;
		cout << "�Է�: ";
		cin >> select;
		switch (select)
		{
		case 1:
			if (st.size() > MAX)
			{
				cout << "�л� ������ ��� á���ϴ�." << endl;
				system("pause");
				break;
			}
			st = regist(st);
			break;
		case 2:
			system("cls");
			for (auto iter = st.begin(); iter != st.end(); iter++)
				show(iter);
			system("pause");
			break;
		case 3:
			system("cls");
			search(st);
			system("pause");
			break;
		case 4:
			system("cls");
			showgrade(st, 'A');
			showgrade(st, 'B');
			showgrade(st, 'C');
			showgrade(st, 'D');
			showgrade(st, 'F');
			system("pause");
			break;
		case 5:
			system("cls");
			showyear(st, 1);
			showyear(st, 2);
			showyear(st, 3);
			system("pause");
			break;
		case 6:
			system("cls");
			release(st);
			system("pause");
			return;
		}
	}
}