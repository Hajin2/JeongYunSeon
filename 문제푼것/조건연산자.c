#include<stdio.h>

void main()
{
	int num1;
	printf("1. ������ �Է��Ͻÿ�: ");
	scanf("%d", &num1);
	(num1 % 5 == 0) ? printf("%d��(��) 5�� ����Դϴ�.\n", num1) : printf("%d��(��) 5�� ����� �ƴմϴ�.\n", num1);

	int korean, english, math;
	printf("2. �� ������ ������ �Է��Ͻÿ�.\n");
	printf("���� ����: ");
	scanf("%d", &korean);
	printf("���� ����: ");
	scanf("%d", &english);
	printf("���� ����: ");
	scanf("%d", &math);
	int sum = korean + english + math;
	float avg = sum / 3.0;
	(avg >= 60) ? printf("��� %.2f�� �հ�\n", avg) : printf("��� %.2f�� ���հ�\n", avg);

	int num2, num3;
	printf("3. �� ������ �Է��Ͻÿ�: ");
	scanf("%d%d", &num2, &num3);
	(num2 > num3) ? printf("ū ��: %d\n", num2) : printf("ū ��: %d\n", num3);

	int num4;
	printf("4. ������ �Է��Ͻÿ�: ");
	scanf("%d", &num4);
	(num4 % 3 == 0) && (num4 % 2 == 0) ? printf("%d��(��) ¦���̸� 3�� ����Դϴ�.\n", num4) : printf("���� ����\n");

	int num5;
	printf("5. ������ �Է��Ͻÿ�: ");
	scanf("%d", &num5);
	(num5 % 5 == 0) || (num5 % 7 == 0) ? printf("%d��(��) 5�� ����ų� 7�� ����Դϴ�.\n", num5) : printf("���� ����\n");
}