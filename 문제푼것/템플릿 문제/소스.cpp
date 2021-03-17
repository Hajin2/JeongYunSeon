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
	cout << "숫자 입력: ";
	cin >> num1;
	cout << "입력받은 숫자 + 1 : " << Add(num1) << endl;
	cout << "두 숫자 입력: ";
	cin >> num1 >> num2;
	cout << "작은 수: " << Min(num1, num2) << endl;
	cout << "세 숫자 입력: ";
	cin >> num1 >> num2 >> num3;
	cout << "세 수 중 큰 수는: " << Max(num1, num2, num3) << endl;
}