#include<stdio.h>

void main()
{
	int x, y, a, b;
	printf("���ο� ���θ� �Է��Ͻÿ�: ");
	scanf("%d%d", &x, &y);
	for (b=1; b<=y ; b++)
	{
		for (a = 1; a <= x; a++)
		{
			if(a==1 || a==x)
				printf("��");

			else
			{
				if (b == 1 || b == y)
					printf("��");

				else
					printf("  ");
			}
		}
		printf("\n");
	}
}