#include<stdio.h>

void main()
{
	int y, a, b;
	printf("���̸� �Է��Ͻÿ�: ");
	scanf("%d", &y);
	for (b = 1; b <= y; b++)
	{
		for (a = 1; a <= y; a++)
		{
			if (b >= a)
				printf("��");

			else
				printf("  ");
		}
		printf("\n");
	}
}