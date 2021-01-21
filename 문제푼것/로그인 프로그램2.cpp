#include<iostream>
#include<string>
#include<Windows.h>
#include<list>
using namespace std;

#define IDMIN 3
#define PWMIN 8
#define MAX 10

struct member
{
	string id;
	string password;
	string nickname;
	int age;
	string phonenum;
	int mileage;
};

void menu(list<member>::iterator iter);
void settingmenu(list<member>::iterator iter);

bool wordcheck(char start, char end, char word)
{
	if (word >= start && word <= end)
		return true;
	else
		return false;
}
void join(list<member>*mem)
{
	member tmp;
	bool engcheck, samecheck;
	while (1)
	{
		engcheck = true;
		samecheck = true;
		system("cls");
		cout << "���̵� �Է�([3���ڡ�] AND [�ѱ�X]): ";
		cin >> tmp.id;
		for (int i = 0; i < tmp.id.length(); i++)
		{
			if (wordcheck('a', 'z', tmp.id[i]) == false && wordcheck('A', 'Z', tmp.id[i]) == false && wordcheck('0', '9', tmp.id[i]) == false)
			{
				engcheck = false;
				break;
			}
		}
		for (auto iter = mem->begin(); iter != mem->end(); iter++)
		{
			if (tmp.id == iter->id)
				samecheck = false;
		}
		if (engcheck == true && samecheck == true && tmp.id.length() >= IDMIN)
			break;
		if (engcheck == false)
			cout << "ID�� ������ �ƴմϴ�." << endl;
		if (samecheck == false)
			cout << "������ ID�� �����մϴ�." << endl;
		if (tmp.id.length() < IDMIN)
			cout << "ID�� 3���� �����Դϴ�." << endl;
		system("pause");
	}
	while (1)
	{
		int countnum = 0;
		engcheck = true;
		string samepw;
		system("cls");
		cout << "��й�ȣ �Է�([8���ڡ�] AND [����] AND [���� ����]): ";
		cin >> tmp.password;
		for (int i = 0; i < tmp.password.length(); i++)
		{
			if (wordcheck('a', 'z', tmp.password[i]) == false && wordcheck('A', 'Z', tmp.password[i]) == false)
			{
				if (wordcheck('0', '9', tmp.password[i]) == true)
					countnum++;
				else
					engcheck = false;
			}
		}
		cout << "��й�ȣ Ȯ��: ";
		cin >> samepw;
		if (tmp.password.length() >= PWMIN && engcheck == true && countnum != 0 && samepw == tmp.password)
			break;
		if (tmp.password.length() < PWMIN)
			cout << "��й�ȣ�� 8���� �����Դϴ�." << endl;
		if (engcheck == false)
			cout << "��й�ȣ�� ������ �ƴմϴ�." << endl;
		if (countnum == 0)
			cout << "���ڰ� ���ԵǾ� ���� �ʽ��ϴ�." << endl;
		if (samepw != tmp.password)
			cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
		system("pause");
	}
	system("cls");
	cout << "�г��� �Է�: ";
	cin >> tmp.nickname;
	cout << "���� �Է�: ";
	cin >> tmp.age;
	cout << "�޴��� ��ȣ �Է�: ";
	cin >> tmp.phonenum;
	cout << "ȸ������ ����!! ���ϸ��� 1000�� ���" << endl;
	tmp.mileage = 1000;
	mem->push_back(tmp);
	system("pause");
}
list<member> login(list<member>mem)
{
	string id_login, pw_login;
	bool id_check, pw_check, logincheck;
	while (1)
	{
		id_check = false;
		pw_check = false;
		logincheck = false;
		system("cls");
		cout << "���̵� �Է�: ";
		cin >> id_login;
		cout << "��й�ȣ �Է�: ";
		cin >> pw_login;
		for (auto iter = mem.begin(); iter != mem.end(); iter++)
		{
			if (iter->id == id_login)
			{
				id_check = true;
				if (iter->password == pw_login)
				{
					pw_check = true;
					logincheck = true;
					menu(iter);
					return mem;
				}
			}
		}
		if (logincheck == false)
		{
			if (id_check == false)
				cout << "�ش� ���̵� �����ϴ�." << endl;
			if (pw_check == false)
				cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
			system("pause");
			continue;
		}
		break;
	}
}
void show(list<member>::iterator iter)
{
	system("cls");
	cout << "============ȸ�� ����============" << endl;
	cout << "ID: " << iter->id << "\t�г���: " << iter->nickname << "" << endl;
	cout << "����: " << iter->age << "\t�޴��� ��ȣ: " << iter->phonenum << "" << endl;
	cout << "���ϸ���: " << iter->mileage << "" << endl;
}
void menu(list<member>::iterator iter)
{
	int menu;
	while (1)
	{
		system("cls");
		cout << "========Menu========" << endl;
		cout << "1. ȸ�� ����" << endl;
		cout << "2. ȸ�� ���� ����" << endl;
		cout << "3. �α׾ƿ�" << endl;
		cout << "�Է�: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			show(iter);
			system("pause");
			break;
		case 2:
			settingmenu(iter);
			break;
		case 3:
			return;
		}
	}
}
void settingmenu(list<member>::iterator iter)
{
	int menu;
	member tmp;
	while (1)
	{
		show(iter);
		cout << "====================" << endl;
		cout << "1. �г��� ����" << endl;
		cout << "2. ���� ����" << endl;
		cout << "3. �޴��� ��ȣ ����" << endl;
		cout << "4. ���ư���" << endl;
		cout << "�Է�: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "���� �г���: " << iter->nickname << "" << endl;
			cout << "������ �г��� �Է�: ";
			cin >> tmp.nickname;
			cout << "" << iter->nickname << " -> " << tmp.nickname << "" << endl;
			iter->nickname = tmp.nickname;
			system("pause");
			break;
		case 2:
			cout << "���� ����: " << iter->age << "" << endl;
			cout << "������ ���� �Է�: ";
			cin >> tmp.age;
			cout << "" << iter->age << " -> " << tmp.age << "" << endl;
			iter->age = tmp.age;
			system("pause");
			break;
		case 3:
			cout << "���� �޴��� ��ȣ: " << iter->phonenum << "" << endl;
			cout << "������ �޴��� ��ȣ �Է�: ";
			cin >> tmp.phonenum;
			cout << "" << iter->phonenum << " -> " << tmp.phonenum << "" << endl;
			iter->phonenum = tmp.phonenum;
			system("pause");
			break;
		case 4:
			return;
		}
	}
}
void main()
{
	list<member> mem;
	int menu;
	while (1)
	{
		system("cls");
		cout << "=====Login=====(ȸ����[" << mem.size() << "��])" << endl;
		cout << "1. ȸ�� ����" << endl;
		cout << "2. �α���" << endl;
		cout << "3. ����" << endl;
		cout << "�Է�: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			if (mem.size() >= MAX)
			{
				cout << "�� �̻� ȸ���� ����� �� �����ϴ�." << endl;
				system("pause");
				break;
			}
			join(&mem);
			break;
		case 2:
			mem = login(mem);
			break;
		case 3:
			return;
		}
	}

}