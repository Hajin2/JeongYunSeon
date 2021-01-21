#include<iostream>
using namespace std;

class TimesTable
{
private:
	int Start;
	int End;

public:
	void SetTT();
	void ShowTT();
};
void TimesTable::SetTT()
{
	while (1)
	{
		cout << "���� �� �Է�: ";
		cin >> Start;
		cout << "�� �� �Է�: ";
		cin >> End;
		if (Start < 2 || Start > 9)
			cout << "���� ���� 2���� �۰ų� 9���� Ů�ϴ�." << endl;
		else if (End < 2 || End >9)
			cout << "�� ���� 2���� �۰ų� 9���� Ů�ϴ�." << endl;
		else if (Start > End)
			cout << "���� ���� �� �ܺ��� Ů�ϴ�." << endl;
		else
			break;
	}
}
void TimesTable::ShowTT()
{
	for (int i = 0; i <= 9; i++)
	{
		for (int j = Start; j <= End; j++)
		{
			if (i == 0)
				cout << "========" << j << "��========\t";
			else
				cout << "\t" << j << " x " << i << " = " << j * i << "\t";
		}
		cout << endl;
	}

}
void main()
{
	TimesTable T;
	T.SetTT();
	T.ShowTT();
}