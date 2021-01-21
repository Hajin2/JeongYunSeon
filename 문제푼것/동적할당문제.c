#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#define MAX 50

typedef struct student
{
	char Name[10];
	int Age;
	int Class;
	int Number;
	char Gender[10];
}Student;

void ShowStudent(Student* St)
{
	printf("\t========%s�л�(%d��)========\n", St->Name, St->Number);
	printf("\t���� : %d,  ���� : %s,  �г� : %d\n", St->Age, St->Gender, St->Class);
	printf("\t===========================\n");
}
void ShowClass(Student* St[], int *StudentCount)
{
	printf("��������������������1 �г⦡������������������\n");
	for (int i = 0; i < *StudentCount; i++)
		if (St[i]->Class == 1)
			ShowStudent(St[i]);
	printf("����������������������������������������������\n");
	printf("��������������������2 �г⦡������������������\n");
	for (int i = 0; i < *StudentCount; i++)
		if (St[i]->Class == 2)
			ShowStudent(St[i]);
	printf("����������������������������������������������\n");
	printf("��������������������3 �г⦡������������������\n");
	for (int i = 0; i < *StudentCount; i++)
		if (St[i]->Class == 3)
			ShowStudent(St[i]);
	printf("����������������������������������������������\n");
}
void SetStudent(Student* St, int *StudentCount)
{
	St->Number = ++(*StudentCount);
	printf("======%d�� �л�======\n", St->Number);
	printf("�̸� �Է� : ");
	scanf("%s", St->Name);
	printf("���� �Է� : ");
	scanf("%d", &St->Age);
	printf("���� �Է� : ");
	scanf("%s", St->Gender);
	printf("�г� �Է�(1~3) : ");
	scanf("%d", &St->Class);
	if (St->Class > 3 || St->Class < 1)
	{
		printf("�г� �߸� �Է�\n");
		free(St);
		(*StudentCount)--;
		system("pause");
	}
}
void SortClass(Student* St[], int *StudentCount)
{
	Student* tmp;
	for (int i = 0; i < *StudentCount - 1; i++)
	{
		for (int j = i + 1; j < *StudentCount; j++)
		{
			if (St[i]->Class > St[j]->Class)
			{
				tmp = St[i];
				St[i] = St[j];
				St[j] = tmp;
			}
		}
	}
}
void SortNumber(Student* St[], int *StudentCount)
{
	Student *tmp2;
	for (int i = 0; i < *StudentCount - 1; i++)
	{
		for (int j = i + 1; j < *StudentCount; j++)
		{
			if (St[i]->Number > St[j]->Number)
			{
				tmp2 = St[i];
				St[i] = St[j];
				St[j] = tmp2;
			}
		}
	}
}
void main()
{
	Student* Student_List[MAX];
	int Select;
	int StudentCount = 0;
	char Sname[10];
	int Sclass;

	while (1)
	{
		system("cls");
		printf("=====�л��������α׷�=====(�� �ο� : %d)\n", StudentCount);
		printf("1.�л� ���\n");
		printf("2.�л� ���(��ȣ��)\n");
		printf("3.�л� ���(�г��)\n");
		printf("4.�г� �˻�\n");
		printf("5.�л� �˻�\n");
		printf("6.������ �л� ����\n");
		printf("7.�л� ��ü ����\n");
		printf("8.����\n");
		printf("�Է� : ");
		scanf("%d", &Select);
		switch (Select)
		{
		case 1:
			system("cls");
			if (StudentCount + 1 >= MAX)
			{
				printf("�л�����(50��)�� ��� á���ϴ�.\n");
				system("pause");
				break;
			}
			Student_List[StudentCount] = (Student*)malloc(sizeof(Student));
			SetStudent(Student_List[StudentCount], &StudentCount);
			break;
		case 2:
			system("cls");
			SortNumber(Student_List, &StudentCount);
			for (int i = 0; i < StudentCount; i++)
				ShowStudent(Student_List[i]);
			system("pause");
			break;
		case 3:
			system("cls");
			SortClass(Student_List, &StudentCount);
			ShowClass(Student_List, &StudentCount);
			system("pause");
			break;
		case 4:
			system("cls");
			printf("�˻��� �г� �Է�(1~3): ");
			scanf("%d", &Sclass);
			for (int i = 0; i < StudentCount; i++)
				if (Student_List[i]->Class == Sclass)
					ShowStudent(Student_List[i]);
			system("pause");
			break;
		case 5:
			system("cls");
			printf("�˻��� �̸� �Է�: ");
			scanf("%s", Sname);
			for (int i = 0; i < StudentCount; i++)
				if (!strcmp(Student_List[i]->Name, Sname))
					ShowStudent(Student_List[i]);
			system("pause");
			break;
		case 6:
			if (StudentCount == 0)
			{
				printf("�� �̻� ������ �л��� �����ϴ�.\n");
				system("pause");
				continue;
			}
			StudentCount--;
			printf("%s�л� �����Ҵ� ���� �Ϸ�\n", Student_List[StudentCount]->Name);
			free(Student_List[StudentCount]);
			Student_List[StudentCount] = NULL;
			system("pause");
			break;
		case 7:
			if (StudentCount == 0)
			{
				printf("�� �̻� ������ �л��� �����ϴ�.\n");
				system("pause");
				continue;
			}
			for (int i = 0; i < StudentCount; i++)
			{
				printf("%s�л� �����Ҵ� ���� �Ϸ�\n", Student_List[i]->Name);
				free(Student_List[i]);
				Student_List[i] = NULL;
			}
			StudentCount = 0;
			system("pause");
			break;
		case 8:
			for (int i = 0; i < StudentCount; i++)
			{
				printf("%s�л� �����Ҵ� ���� �Ϸ�\n", Student_List[i]->Name);
				free(Student_List[i]);
			}
			return;
		}
	}
}