#include<stdio.h>

void main()
{
	int num1;
	printf("1. ������ �Է��Ͻÿ�: ");
	scanf("%d", &num1);
	printf("%d��(��) 3�� ���", num1);
	if (num1 % 3 == 0)
	{
		printf("�Դϴ�.\n");
	}
	if (num1 % 3 != 0)
	{
		printf("�� �ƴմϴ�.\n");
	}

	printf("2. ������ �Է��Ͻÿ�: ");
	scanf("%d", &num1);
	printf("%d�� ������ ", num1);
	if (num1 < 0)
	{
		printf("%d�Դϴ�.\n", -num1);
	}
	if (num1 >= 0)
	{
		printf("%d�Դϴ�.\n", num1);
	}

	printf("3. ������ �Է��Ͻÿ�: ");
	scanf("%d", &num1);
	printf("%d��(��) ", num1);
	if (num1 % 2 == 0)
	{
		printf("¦���Դϴ�.\n");
	}
	if (num1 % 2 != 0)
	{
		printf("Ȧ���Դϴ�.\n");
	}

	int num2;
	printf("4. ���� �� ���� �Է��Ͻÿ�: ");
	scanf("%d%d", &num1, &num2);
	printf("Max=");
	if (num1 >= num2)
	{
		printf("%d\n", num1);
	}
	if (num1 < num2)
	{
		printf("%d\n", num2);
	}

	int num3;
	printf("5. ���� �� ���� �Է��Ͻÿ�: ");
	scanf("%d%d%d", &num1, &num2, &num3);
	printf("Max=");
	if (num1 > num2 && num1 > num3)
	{
		printf("%d\n", num1);
	}
	if (num2 > num3 && num2 > num1)
	{
		printf("%d\n", num2);
	}
	if (num3 > num1 && num3 > num2)
	{
		printf("%d\n", num3);
	}
	if (num1 == num2 == num3)
	{
		printf("%d\n", num1);
	}

	printf("6. ���� �� ���� �Է��Ͻÿ�: ");
	scanf("%d%d", &num1, &num2);
	if (num1 >= num2)
	{
		printf("ū ���� %d�̸� ", num1);
		if (num1 % 2 == 0)
		{
			printf("¦���Դϴ�.\n");
		}
		if (num1 % 2 != 0)
		{
			printf("Ȧ���Դϴ�.\n");
		}
	}

	if(num1 < num2)
	{
		printf("ū ���� %d�̸� ", num2);
		if (num2 % 2 == 0)
		{
			printf("¦���Դϴ�.\n");
		}
		if (num2 % 2 != 0)
		{
			printf("Ȧ���Դϴ�.\n");
		}
	}

	printf("7. ���� �� ���� �Է��Ͻÿ�: ");
	scanf("%d%d", &num1, &num2);
	int sum = num1 + num2;
	if (sum % 2 != 0 && sum % 3 == 0)
	{
		printf("%d�� %d�� ��: %d\n", num1, num2, sum);
		printf("Ȧ���̸� 3�� ���");
	}
	else
	{
		printf("�ش������ �����ϴ�.");
	}
}