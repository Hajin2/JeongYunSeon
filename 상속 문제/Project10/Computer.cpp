#include "Computer.h"

Computer::Computer()
{
	m_strName = "Attents";
	m_strSt = "Off";
	m_strGp = "GTX1060Ti";
	m_strCpu = "i7";
	m_strMm = "16G";
}
void Computer::Menu(list<member>::iterator iter)
{
	int iMenu;
	cout << "��ǻ�� on" << endl;
	Sleep(1000);
	m_strSt = "On";
	while (1)
	{
		system("cls");
		cout << "===== ȯ �� �� �� �� =====" << endl;
		cout << "1. ��ǻ�� ����" << endl;
		cout << "2. ���" << endl;
		cout << "3. ȸ�� ����" << endl;
		cout << "4. ȸ�� ���� ����" << endl;
		cout << "5. off" << endl;
		cout << "�Է� >>";
		cin >> iMenu;
		switch (iMenu)
		{
		case COM_STATUS:
			Status();
			break;
		case COM_PROGRAM:
			Program();
			break;
		case COM_INFO:
			Info(iter);
			break;
		case COM_CHANGE:
			SettingMenu(iter);
			break;
		case COM_OFF:
			for (int i = 0; i < 5; i++)
			{
				cout << "off" << 5 - i << "�� ��" << endl;
				Sleep(1000);
			}
			return;
		}
	}
}
void Computer::Status()
{
	system("cls");
	cout << "��ǰ��: " << m_strName << endl;
	cout << "���� ����: " << m_strSt << endl;
	cout << "�׷���ī��: " << m_strGp << endl;
	cout << "CPU: " << m_strCpu << endl;
	cout << "�޸�: " << m_strMm << endl;
	system("pause");
}
void Computer::Program()
{
	int iMenu;
	while (1)
	{
		system("cls");
		cout << "1. ����" << endl;
		cout << "2. �޸���" << endl;
		cout << "3. �׸���" << endl;
		cout << "4. ���ư���" << endl;
		cout << "���� >>>> ";
		cin >> iMenu;
		switch (iMenu)
		{
		case 1:
			system("calc");
			break;
		case 2:
			system("notepad");
			break;
		case 3:
			system("mspaint");
			break;
		case 4:
			return;
		}
		system("pause");
		system("cls");
	}
}
void Computer::Info(list<member>::iterator iter)
{
	system("cls");
	cout << "============ȸ�� ����============" << endl;
	cout << "ID: " << iter->id << "\t�г���: " << iter->nickname << "" << endl;
	cout << "����: " << iter->age << "\t�޴��� ��ȣ: " << iter->phonenum << "" << endl;
	cout << "���ϸ���: " << iter->mileage << "" << endl;
}
void Computer::SettingMenu(list<member>::iterator iter)
{
	int menu;
	member tmp;
	while (1)
	{
		Info(iter);
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