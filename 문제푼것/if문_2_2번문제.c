#include<stdio.h>

void main()
{
	int time, cost;
	printf("�¸� �̿�ð��� �Է��Ͻÿ�: ");
	scanf("%d", &time);
	printf("%d�� ž�¿��: ", time);
	if (time <= 30)
	{
		cost = 3000;
	}
	else
	{
		if ((time - 30) % 10 == 0)
		{
			cost = 3000 + ((time - 30) / 10) * 500;
		}
		else
		{
			cost = 3000 + ((time - 30) / 10) * 500 + 500;
		}
	}
	printf("%d��", cost);
}