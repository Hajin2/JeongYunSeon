#include<stdio.h>
#include<map>//�����Ʈ��
//����Ž��Ʈ��
//B tree, AVL tree, Red Black tree > ���ʰ� �������� �뷱���� ��� ���� Ʈ��

typedef struct Student
{
	char Name[256];
	int Age;
	char Major[256];
}Student;

Student CreateStudent()
{
	Student st;
	printf("�̸� �Է�: ");
	scanf("%s", st.Name);
	printf("���� �Է�: ");
	scanf("%d", &st.Age);
	printf("�а� �Է�: ");
	scanf("%s", st.Major);
	return st;
}
void ShowStudent(Student st, int Num)
{
	printf("�й�(%d)\n", Num);
	printf("�̸�: %s\t", st.Name);
	printf("����: %d\t", st.Age);
	printf("�а�: %s\n", st.Major);
}
void main()
{
	std::map<int, Student> mapStudent;
	int StudentNum = 20200001;
	//mapStudent.insert(std::make_pair(20200001, CreateStudent())); ������ 2020001�� ����
	//mapStudent[20200002] = CreateStudent(); //���� ����
	//mapStudent[20200001] = CreateStudent(); //���� ����(key�� �ߺ��� �Ұ���)
	for (int i = 0; i < 5; i++)
	{
		mapStudent.insert(std::make_pair(StudentNum++, CreateStudent()));
	}
	for (auto iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
	{
		ShowStudent(iter->second, iter->first);
	}
	mapStudent.erase(20200001); //key�� ������ ����
	mapStudent.at(20200001); //�ذ� ����
	mapStudent[20200001];
	mapStudent.find(20200001); //���� �˻�

}