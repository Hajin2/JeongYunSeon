#include<stdio.h>
#define TRUE 1

void main()
{
	int i = 0, j = 0, sum = 0;
	while (TRUE)
	{
		printf("1. 10~20 ���� �� �Է�: ");
		scanf("%d", &i);
		if (i >= 10 && i <= 20)
			break;
		printf("�߸� �Է�\n");
	}
	while (j <= i)
	{
		sum += j;
		j++;
	}
	printf("1~%d �����հ�: %d\n", i, sum);

	int num = 1;
	printf("2. Hello ���\n");
	while (num <= 5)
	{
	printf("Hello\n");
	num++;
	}

	int num2 = 1, sum2 = 0;
	printf("3. ���� �ݺ� �Է�(0 �Է� �� ����)\n");
	while (num2)
	{
		printf("���� �Է�: ");
		scanf("%d", &num2);
		sum2 += num2;
	}
	printf("���� �հ�: %d\n", sum2);

	int num3, num4 = 2;
	printf("4. �Ҽ� �Ǻ�\n");
	printf("���� �Է�:");
	scanf("%d", &num3);
	if (num3 == 1)
		printf("%d�� �Ҽ��� �ƴմϴ�.\n", num3);
	while (TRUE)
	{
		if (num3 > num4)
		{
			if (num3 % num4 == 0)
			{
				printf("%d��(��) �Ҽ��� �ƴմϴ�.\n", num3);
				break;
			}
			else
				num4++;
		}
		else
		{
			printf("%d��(��) �Ҽ��Դϴ�.\n", num3);
			break;
		}
	}

	int num5;
	printf("5. �Էµ� ���� �Ųٷ� ���\n");
	printf("���� �Է�: ");
	scanf("%d", &num5);
	while (num5)
	{
		printf("%d", num5 % 10);
		num5 /= 10;
	}

	int num6, sum3 = 0;
	printf("\n6. �Էµ� ������ ���ڸ��� �հ�\n");
	printf("���� �Է�: ");
	scanf("%d", &num6);
	while (num6)
	{
		sum3 += num6 % 10;
		num6 /= 10;
	}
	printf("%d", sum3);
}