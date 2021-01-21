#include<stdio.h>
#include<list>
#include<vector>
#include<map>//�����Ʈ��
//����Ž��Ʈ��
//B tree, AVL tree, Red Black tree > ���ʰ� �������� �뷱���� ��� ���� Ʈ��

//vector(������ ���� ������ �߿��� ��
//����
//Ư�� ���ҿ� ������ ������.
//������ ��ġ�� ������ �߰��ϴ� ������ ������.
//����
//���̿� �ִ� ������ �߰� ���� ���� ���� ������.

//list(�������� �������� �߰� ���� ���� ���� �߿��Ҷ�
//����
//���̿� �ִ� ������ �߰� ���� ���� ���� ������.
//����
//Ư�� ���ҿ� ������ ������.
//������ ��ġ�� ������ �߰��ϴ� ������ ������.

void ShowVector(std::vector<int>iVector)
{
	//iVector.size() ������ ���� ��ȯ
	for (int i = 0; i < iVector.size(); i++)
		printf("iVector[%d]: %d\n", i, iVector[i]);
}
void ShowVector2(std::vector<int>iVector)
{
	for (int i = 0; i < iVector.size(); i++)
		printf("iVector.at(%d): %d\n", i, iVector.at(i));
}
void ShowVector3(std::vector<int>iVector)
{
	for (auto iter = iVector.begin(); iter != iVector.end(); iter++)
		printf("*iter: %d\n", *iter);
}
int main()
{
	std::vector<int> iVector;

	for (int i = 1; i <= 10; i++)
	{
		iVector.push_back(i);
	}
	printf("Front: %d\tBack: %d\n", iVector.front(), iVector.back());
	ShowVector(iVector);
	ShowVector2(iVector);
	ShowVector3(iVector);

	//iVector.clear() ���� ��ü ����
	//iVector.empty() ����ִ��� Ȯ���ϴ� �Լ� ��������� �� ��ȯ
	//iVector.erase() ���ϴ� �͸� ����
	//iter �����ּ� ��ȯ

	auto iter = find(iVector.begin(), iVector.end(), 11);
	if (iter == iVector.end())
		printf("�����Ͱ� �������� �ʽ��ϴ�.\n");
	else
	{
		iVector.erase(iter);
		ShowVector3(iVector);
	}

	iter = find(iVector.begin(), iVector.end(), 6);
	if (iter == iVector.end())
		printf("�����Ͱ� �������� �ʽ��ϴ�.\n");
	else
	{
		iVector.erase(iter);
		ShowVector3(iVector);
	}

	iter = find(iVector.begin(), iVector.end(), 7);
	if (iter == iVector.end())
		printf("�����Ͱ� �������� �ʽ��ϴ�.\n");
	else
	{
		iVector.insert(iter, 11);
		ShowVector3(iVector);
	}
	iVector.pop_back();//������ ���� ����

	std::list<int> iList;
	iList.pop_front(); //���� ������ ����
	iList.push_front(); //���� ������ �߰�

}
