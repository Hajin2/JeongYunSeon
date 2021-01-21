#include<stdio.h>
#define SIZE 8

void ConvertToUppercase(char* str)
{
	int i = 0;
	while (str[i] != NULL)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
}

void MaxNum(int* num1, int* num2, int *max)
{
	if (*num1 >= *num2)
		*max = *num1;
	else
		*max = *num2;
}

void Sum(int* num, int* result)
{
	*result = 0;
	for (int i = 1; i <= *num; i++)
		*result += i;
}

void Ascending(int* arr)
{
	int tmp;
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = i + 1; j < SIZE; j++)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
void main()
{
	char string[20];
	printf("1. ���ڿ��� �Է��Ͻÿ�: ");
	scanf("%s", string);
	printf("�Լ� ȣ�� �� = %s\n", string);
	ConvertToUppercase(string);
	printf("�Լ� ȣ�� �� = %s\n", string);

	int num1, num2, max;
	printf("2. �� ������ �Է��Ͻÿ�: ");
	scanf("%d%d", &num1, &num2);
	MaxNum(&num1, &num2, &max);
	printf("%d��(��) %d �� ū ���� %d\n", num1, num2, max);

	int num, result;
	printf("3. ������ �Է��Ͻÿ�: ");
	scanf("%d", &num);
	Sum(&num, &result);
	printf("1 ~ %d�� ����: %d\n", num, result);

	int arr[SIZE];
	printf("4. �������� ����\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("[%d]��° ���� �Է�: ", i);
		scanf("%d", &arr[i]);
	}
	printf(" ���� ��: ");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
		if (i == SIZE - 1)
			printf("\n");
	}
	Ascending(arr);
	printf("���� ��: ");
	for (int i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
}