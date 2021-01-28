#include "Login.h"

Login::Login()
{
	m_EngCheck = true;
	m_SameCheck = true;
	m_IDCheck = false;
	m_PWCheck = false;
	m_LoginCheck = false;
}
void Login::LoginMenu()
{
	int menu;
	while (1)
	{
		system("cls");
		cout << "=====Login=====(ȸ����[" << m_Member.size() << "��])" << endl;
		cout << "  1. ȸ�� ����" << endl;
		cout << "  2. �α���" << endl;
		cout << "  3. ����" << endl;
		cout << "�Է�: ";
		cin >> menu;
		switch (menu)
		{
		case MENU_JOIN:
			Join();
			break;
		case MENU_LOGIN:
			LoginInput();
			break;
		case MENU_EXIT:
			return;
		}
	}
}
void Login::Join()
{
	member tmp;
	while (1)
	{
		system("cls");
		cout << "���̵� �Է�([3���ڡ�] AND [�ѱ�X]):";
		cin >> tmp.id;
		for (int i = 0; i < tmp.id.length(); i++)
		{
			if (WordCheck('a', 'z', tmp.id[i]) == false && WordCheck('A', 'Z', tmp.id[i]) == false
				&& WordCheck('0', '9', tmp.id[i]) == false)
			{
				m_EngCheck = false;
				break;
			}
		}
		for (auto iter = m_Member.begin(); iter != m_Member.end(); iter++)
		{
			if (tmp.id == iter->id)
				m_SameCheck = false;
		}
		if (m_EngCheck == true && m_SameCheck == true && tmp.id.length() >= IDMIN)
			break;
		if (m_EngCheck == false)
			cout << "ID�� ������ �ƴմϴ�." << endl;
		if (m_SameCheck == false)
			cout << "������ ID�� �����մϴ�." << endl;
		if (tmp.id.length() < IDMIN)
			cout << "ID�� 3���� �����Դϴ�." << endl;
		system("pause");
	}
	while (1)
	{
		int countnum = 0;
		m_EngCheck = true;
		string samepw;
		system("cls");
		cout << "��й�ȣ �Է�([8���ڡ�] AND [����] AND [���� ����]): ";
		cin >> tmp.password;
		for (int i = 0; i < tmp.password.length(); i++)
		{
			if (WordCheck('a', 'z', tmp.password[i]) == false && WordCheck('A', 'Z', tmp.password[i]) == false)
			{
				if (WordCheck('0', '9', tmp.password[i]) == true)
					countnum++;
				else
					m_EngCheck = false;
			}
		}
		cout << "��й�ȣ Ȯ��: ";
		cin >> samepw;
		if (tmp.password.length() >= PWMIN && m_EngCheck == true && countnum != 0 && samepw == tmp.password)
			break;
		if (tmp.password.length() < PWMIN)
			cout << "��й�ȣ�� 8���� �����Դϴ�." << endl;
		if (m_EngCheck == false)
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
	m_Member.push_back(tmp);
	system("pause");
}
bool Login::WordCheck(char start, char end, char word)
{
	if (word >= start && word <= end)
		return true;
	else
		return false;
}
void Login::LoginInput()
{
	string id_login, pw_login;
	while (1)
	{
		system("cls");
		cout << "���̵� �Է�: ";
		cin >> id_login;
		cout << "��й�ȣ �Է�: ";
		cin >> pw_login;
		for (auto iter = m_Member.begin(); iter != m_Member.end(); iter++)
		{
			if (iter->id == id_login)
			{
				m_IDCheck = true;
				if (iter->password == pw_login)
				{
					m_PWCheck = true;
					m_LoginCheck = true;
					//Menu(iter);
				}
			}
		}
		if (m_LoginCheck == false)
		{
			if (m_IDCheck == false)
				cout << "�ش� ���̵� �����ϴ�." << endl;
			if (m_PWCheck == false)
				cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
			system("pause");
			continue;
		}
		break;
	}
}