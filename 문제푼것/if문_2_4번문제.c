#include<stdio.h>
void main()
{
	int num, money;
	printf("������ ���� ������ �Է��Ͻÿ�: ");
	scanf("%d", &num);
	printf("��ũ %d�� ����: ", num);
	money = num * 5000;
	if (num >= 10 && num < 100)
	{
		money = 0.9 * money;
		printf("%d��", money);
	}
	else if (num >= 100)
	{
		money = 0.88*money;
		printf("%d��", money);
	}
	else
	{
		printf("%d��", money);
	}
}