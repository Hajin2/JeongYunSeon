#include<stdio.h>
#include<string.h>

int length(char str[])
{
	int i = 0;
	while (str[i] != NULL)
	{
		i++;
	}
	return i;
}
void main()
{
	char str[10] = "Hello";
	printf("%s ���ڿ��� ����: %d\n", str, length(str));
}