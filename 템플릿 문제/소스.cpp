#include<iostream>
using namespace std;

template<typename Type>
Type Add(Type num)
{
	return ++num;
}

template<typename Type>
Type Min(Type num1, Type num2)
{
	if (num1 < num2)
		return num1;
	else
		return num2;
}

template<typename Type>
Type Max(Type num1, Type num2, Type num3)
{
	if (num1 > num2 && num1 > num3)
		return num1;
	else if (num2 > num3)
		return num2;
	else
		return num3;
}

void main()
{
	int num1, num2, num3;
	cout << "���� �Է�: ";
	cin >> num1;
	cout << "�Է¹��� ���� + 1 : " << Add(num1) << endl;
	cout << "�� ���� �Է�: ";
	cin >> num1 >> num2;
	cout << "���� ��: " << Min(num1, num2) << endl;
	cout << "�� ���� �Է�: ";
	cin >> num1 >> num2 >> num3;
	cout << "�� �� �� ū ����: " << Max(num1, num2, num3) << endl;
}