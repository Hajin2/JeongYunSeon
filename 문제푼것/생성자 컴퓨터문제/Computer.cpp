#include "Computer.h"

Computer::Computer()
{
	m_strName = "Atents";
	m_strSt = "OFF";
	m_strGp = "GTX990";
	m_strCpu = "i7";
	m_strMm = "8G";
}
void Computer::Menu()
{
	int imenu;
	cout << "����ȣ ��ǻ�� on" << endl;
	Sleep(1000);
	m_strSt = "ON";
	while (1)
	{
		system("cls");
		cout << "===== ȯ �� �� �� �� =====" << endl;
		cout << "1. ��ǻ�� ����" << endl;
		cout << "2. �� ��" << endl;
		cout << "3. off" << endl;
		cout << "�Է� >>>> ";
		cin >> imenu;
		switch (imenu)
		{
		case 1:
			Status();
			break;
		case 2:
			Program();
			break;
		case 3:
			for (int i = 0; i < 5; i++)
			{
				cout << "off " << 5-i << "�� ��" << endl;
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
	int imenu;
	while (1)
	{
		system("cls");
		cout << "1. ����" << endl;
		cout << "2. �޸���" << endl;
		cout << "3. �׸���" << endl;
		cout << "4. ���ư���" << endl;
		cout << "���� >>>> ";
		cin >> imenu;
		switch (imenu)
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