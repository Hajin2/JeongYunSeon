#pragma once
#include<iostream>
using namespace std;

template<typename Type>
class Queue
{
private:
	int m_iFront, m_iBack, m_iSize;
	Type* m_pQueue;
public:
	Queue(int size);
	void Push(const Type& data);
	void Pop();
	Type Front();
	Type Back();
	void Print();
	~Queue();
};

template<typename Type>
Queue<Type>::Queue(int size)
{
	m_iSize = size;
	m_iBack = -1;
	m_iFront = 0;
	m_pQueue = new Type[m_iSize];
}

template<typename Type>
void Queue<Type>::Push(const Type& data)
{
	m_pQueue[++m_iBack] = data;
}

template<typename Type>
void Queue<Type>::Pop()
{
	m_pQueue[m_iFront++] = NULL;
}

template<typename Type>
Type Queue<Type>::Front()
{
	if (m_iFront > m_iBack)
		return -1;
	else
		return m_pQueue[m_iFront];
}

template<typename Type>
Type Queue<Type>::Back()
{
	if (m_iFront > m_iBack)
		return -1;
	else
		return m_pQueue[m_iBack];
}

template<typename Type>
void Queue<Type>::Print()
{
	for (int i = 0; i < m_iSize; i++)
	{
		cout << m_pQueue[i] << endl;
	}
}

template<typename Type>
Queue<Type>::~Queue()
{
	delete m_pQueue;
}