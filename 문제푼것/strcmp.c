#include<stdio.h>
#include<string.h>

void main()
{
	FILE* f = fopen("Alice.txt", "r");
	if (f == NULL)
		printf("�ش� �̸��� ������ �����ϴ�.");
	else
	{
		fread(buf, sizeof(buf), 1, f);
		printf("%s\n", buf);
	}
	fclose(f);
}