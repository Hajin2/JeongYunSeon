#include<stdio.h>

void main()
{
	char str
	int num;

	printf("=====1������=====\n");
	printf("���Ϲ��ڸ� �Է��Ͻÿ�: ");
	scanf("%c", &str);
	printf("������ �Է��Ͻÿ�: ");
	scanf("%d", &num);
	printf("%c + %d = %c\n", str, num, num + str);

	float num2;

	printf("=====2������=====\n");
	printf("�Ҽ��� ���� �Է��Ͻÿ�: ");
	scanf("%f", &num2);
	printf("�Ҽ�����: %.2f\n", num2);

	int korean, math, english;

	printf("=====3������=====\n");
	printf("���� ������ �Է��Ͻÿ�: ");
	scanf("%d", &korean);
	printf("���� ������ �Է��Ͻÿ�: ");
	scanf("%d", &math);
	printf("���� ������ �Է��Ͻÿ�: ");
	scanf("%d", &english);
	int sum = korean + math + english;
	float avg = sum / 3.0;
	printf("�հ� ����:%d      ��� ����:%.2f\n", sum, avg);

	char name[10];
	int age;

	printf("=====4������=====\n");
	printf("�̸��� �Է��Ͻÿ�: ");
	scanf("%s", name);
	printf("%s���� ���̸� �Է��Ͻÿ�: ", name);
	scanf("%d", &age);
	printf("%s���� ���̴� %d���Դϴ�.", name, age);
}