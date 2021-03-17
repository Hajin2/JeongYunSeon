#pragma once
#include<iostream>
using namespace std;

template<typename Type>
class Stack
{
private:
	Type* m_pStack;
	int m_iSize, m_iTop;
public:
	Stack(int num);
	void Pop();
	void Push(Type data);
	void Print();
};

template<typename Type>
Stack<Type>::Stack(int num)
{
	m_iTop = 0;
	m_iSize = num;
	m_pStack = new Type[m_iSize];
}

template<typename Type>
void Stack<Type>::Pop()
{
	m_pStack[--m_iTop] = NULL;
}

template<typename Type>
void Stack<Type>::Push(Type data)
{
	m_pStack[m_iTop++] = data;
}

template<typename Type>
void Stack<Type>::Print()
{
	for (int i = 0 ; i < m_iSize ; i++)
	{
		cout << m_pStack[i] << endl;
	}
}