#include<stdio.h>

void main()
{
	char str[5];
	for (int i = 0; i < 5; i++)
	{
		printf("%d��° ���� �� : ", i + 1);
		scanf("%c", &str[i]);
		scanf("%*c");
	}
	for (int i = 0; i < 5; i++)
		printf("%c ", str[i]);
}
