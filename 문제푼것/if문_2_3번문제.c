#include<stdio.h>

void main()
{
	int num, fee;
	printf("������ ���ö� ������ �Է��Ͻÿ�: ");
	scanf("%d", &num);
	printf("���ö� %d�� ����: ", num);
	if (num <= 10)
	{
		fee = 2500 * num;
		printf("%d��", fee);
	}
	else
	{
		fee = 25000 + 2400 * (num-10);
		printf("%d��", fee);
	}
}