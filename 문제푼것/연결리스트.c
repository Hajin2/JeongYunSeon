#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
typedef struct Student
{
	char Name[20];
	char Address[20];
	int Korean, English, Math, Sum, Age;
	float Average;
	struct Student* Next;
}Student;
void Menu()
{
	system("cls");
	printf("1. �л� ���\n");
	printf("2. �л� �˻�\n");
	printf("3. �л� ���\n");
	printf("4. �л� ����\n");
	printf("5. �л� ����\n");
	printf("6. ����\n");
	printf("����: ");
}
void ShowSt(Student* St)
{
	printf("%8s\t%8s\t%8s\t\n", "�л� �̸�", "�л� ����", "�л� �ּ�");
	while (St != NULL)
	{
		printf("%8s\t%8d\t%8s\n", St->Name, St->Age, St->Address);
		St = St->Next;
	}
	printf("�л� �������� ������ �˻��� �̿��ϼ���!!\n");
}
Student* NewSt()
{
	Student* tmp;
	tmp = (Student*)malloc(sizeof(Student));
	tmp->Next = NULL;
	return tmp;
}
void Insert(Student **Head)
{
	if (*Head == NULL)
	{
		*Head = NewSt();
		printf("�л� �̸� �Է�: ");
		scanf("%s", (*Head)->Name);
		printf("%s �л� ���� �Է�: ", (*Head)->Name);
		scanf("%d", &(*Head)->Age);
		printf("%s �л� �ּ� �Է�: ", (*Head)->Name);
		scanf("%s", (*Head)->Address);
		printf("%s �л� ���� ����: ", (*Head)->Name);
		scanf("%d", &(*Head)->Korean);
		printf("%s �л� ���� ����: ", (*Head)->Name);
		scanf("%d", &(*Head)->English);
		printf("%s �л� ���� ����: ", (*Head)->Name);
		scanf("%d", &(*Head)->Math);
		printf("�л� ���� �Է� �Ϸ�\n");
		return;
	}
	Insert(&(*Head)->Next);
}
Student* Search(Student *Head, char *Name)
{
	system("cls");
	if (Head == NULL)
	{
		printf("ã�� �л��� �����ϴ�.\n");
		return 0;
	}
	if (!(strcmp(Head->Name, Name)))
	{
		Head->Sum = (Head->English) + (Head->Korean) + (Head->Math);
		Head->Average = (Head->Sum) / 3.0;
		printf("�л� ���� �˻� �Ϸ�\n");
		printf(" = = = = = Information = = = = =\n");
		printf("�л� �̸�: %s\n", Head->Name);
		printf("�л� ����: %d��\n", Head->Age);
		printf("�л� �ּ�: %s\n", Head->Address);
		printf("���� ����: %d��\n", Head->Korean);
		printf("���� ����: %d��\n", Head->English);
		printf("���� ����: %d��\n", Head->Math);
		printf("�հ� ����: %d��\n", Head->Sum);
		printf("��� ����: %.2f��\n", Head->Average);
		printf("�л� ���: ");
		if (Head->Average > 90)
			printf("A���\n");
		else if (Head->Average > 80)
			printf("B���\n");
		else if (Head->Average > 70)
			printf("C���\n");
		else if (Head->Average > 60)
			printf("D���\n");
		else
			printf("F���\n");
		return Head;
	}
	Search(Head->Next, Name);
}
void Modify(Student *Head, char *Name)
{
	int Menu;
	char add[20];
	Head = Search(Head, Name);
	if (Head != NULL)
	{
		while (1)
		{
			Search(Head, Name);
			printf("\n������ �׸��� �����Ͻÿ�\n");
			printf("1. �̸�\t2. ����\t3. �ּ�\t4. ����\t5. ���� ����\n");
			printf("����: ");
			scanf("%d", &Menu);
			switch (Menu)
			{
			case 1:
				printf("���� �̸�: %s\n", Head->Name);
				printf("������ �̸�: ");
				scanf("%s", Name);
				printf("%s -> %s�� �̸� ���� �Ϸ�\n", Head->Name, Name);
				strcpy(Head->Name, Name);
				system("pause");
				break;
			case 2:
				printf("���� ����: %d��\n", Head->Age);
				printf("������ ����: ");
				scanf("%d", &Head->Age);
				printf("���� ���� �Ϸ�\n");
				system("pause");
				break;
			case 3:
				printf("���� �ּ�: %s\n", Head->Address);
				printf("������ �ּ�: ");
				scanf("%s", add);
				printf("%s -> %s�� �̸� ���� �Ϸ�\n", Head->Address, add);
				strcpy(Head->Address, add);
				system("pause");
				break;
			case 4:
				printf("���� ����\n");
				printf("����: %d\t����:%d\t����:%d\n", Head->Korean, Head->English, Head->Math);
				printf("������ ���� ����: ");
				scanf("%d", &Head->Korean);
				printf("������ ���� ����: ");
				scanf("%d", &Head->English);
				printf("������ ���� ����: ");
				scanf("%d", &Head->Math);
				printf("���� ���� �Ϸ�\n");
				system("pause");
				break;
			case 5:
				printf("������ �����մϴ�\n");
				return;
			}
		}
	}
}
void Delete(Student **Head, char *Name)
{
	Student *tmp;
	if (*Head == NULL)
	{
		printf("������ ����� �����ϴ�.\n");
		system("pause");
		return;
	}
	if (!(strcmp((*Head)->Name, Name)))
	{
		tmp = *Head;
		*Head = (*Head)->Next;
		free(tmp);
		printf("���� �Ϸ�\n");
		system("pause");
		return;
	}
	Delete(&(*Head)->Next, Name);
}
void Close(Student *Head)
{
	if (Head == NULL)
		return;
	Close(Head->Next);
	free(Head);
}
void main()
{
	int Select;
	char Name[20];
	Student *Head = NULL;
	while (1)
	{
		Menu();
		scanf("%d", &Select);
		switch (Select)
		{
		case 1:
			system("cls");
			Insert(&Head);
			system("pause");
			break;
		case 2:
			if (Head == NULL)
				continue;
			system("cls");
			printf("�˻��� �̸� �Է�: ");
			scanf("%s", Name);
			Search(Head, &Name);
			system("pause");
			break;
		case 3:
			if (Head == NULL)
				continue;
			system("cls");
			ShowSt(Head);
			system("pause");
			break;
		case 4:
			if (Head == NULL)
				continue;
			system("cls");
			printf("������ �л� �̸���? ");
			scanf("%s", Name);
			Modify(Head, &Name);
			system("pause");
			break;
		case 5:
			if (Head == NULL)
				continue;
			system("cls");
			printf("������ �л� �̸�: ");
			scanf("%s", Name);
			Delete(&Head, &Name);
			break;
		case 6:
			Close(Head);
			return;
		}
	}
}
