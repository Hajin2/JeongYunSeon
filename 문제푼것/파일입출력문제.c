#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#define MAX 50

typedef struct student
{
	int Number;
	char Name[10];
	int Age;
	char Gender[10];
	int Class;
}Student;
void ShowStudent(Student* St)
{
	printf("\t========%s�л�(%d��)========\n", St->Name, St->Number);
	printf("\t���� : %d,  ���� : %s,  �г� : %d\n", St->Age, St->Gender, St->Class);
	printf("\t===========================\n");
}
void ShowClass(Student* St[], int Class, int* StudentCount)
{
	printf("��������������������%d �г⦡������������������\n", Class);
	for (int i = 0; i < *StudentCount; i++)
		if (St[i]->Class == Class)
			ShowStudent(St[i]);
	printf("����������������������������������������������\n");
}
void SetStudent(Student* St, int* StudentCount)
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
void SortClass(Student* St[], int* StudentCount)
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
void SortNumber(Student* St[], int* StudentCount)
{
	Student* tmp2;
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
void WriteStudent(Student* St[], FILE* f, int *StudentCount)
{
	f = fopen("�л� ����.txt", "w");
	fprintf(f, "%d\n", *StudentCount);
	for (int i = 0; i < *StudentCount; i++)
	{
		fprintf(f, "%s %d %s %d\n", St[i]->Name, St[i]->Age, St[i]->Gender, St[i]->Class);
	}
	fclose(f);
	printf("���� �Ϸ�!!\n");
	system("pause");
}
void ReadStudent(Student* St[], FILE* f, int *StudentCount)
{
	f = fopen("�л� ����.txt", "r");
	if (f == NULL)
		printf("�ش� �̸��� ������ �����ϴ�.\n");
	else
	{
		for (int i = 0; i < *StudentCount; i++)
		{
			free(St[i]);
			St[i] = NULL;
		}
		fscanf(f, "%d\n", StudentCount);
		for (int i = 0; i < *StudentCount; i++)
		{
			St[i] = (Student*)malloc(sizeof(Student));
			fscanf(f, "%s %d %s %d\n", St[i]->Name, &St[i]->Age, St[i]->Gender, &St[i]->Class);
			St[i]->Number = i + 1;
		}
		fclose(f);
	}
}
void main()
{
	Student* Student_List[MAX];
	int Select;
	int StudentCount = 0;
	char Sname[10];
	int Sclass;
	FILE* f = NULL;

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
		printf("8.�л� ���� ����\n");
		printf("9.�л� ���� �ҷ�����\n");
		printf("10.����\n");
		printf("�Է� : ");
		scanf("%d", &Select);
		switch (Select)
		{
		case 1:
			system("cls");
			if (StudentCount + 1 >= MAX)
			{
				printf("�л�����(%d��)�� ��� á���ϴ�.\n", MAX);
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
			for (int i = 1; i <= 3; i++)
				ShowClass(Student_List, i, &StudentCount);
			system("pause");
			break;
		case 4:
			system("cls");
			printf("�˻��� �г� �Է�(1~3): ");
			scanf("%d", &Sclass);
			ShowClass(Student_List, Sclass, &StudentCount);
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
			WriteStudent(Student_List, f, &StudentCount);
			break;
		case 9:
			ReadStudent(Student_List, f, &StudentCount);
			break;
		case 10:
			for (int i = 0; i < StudentCount; i++)
			{
				printf("%s�л� �����Ҵ� ���� �Ϸ�\n", Student_List[i]->Name);
				free(Student_List[i]);
			}
			return;
		}
	}
}