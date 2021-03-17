#include"Stack.h"
#include"Queue.h"

void main()
{
	Stack<int> st(3);
	st.Push(3);
	st.Push(5);
	st.Push(7);
	st.Print();
	st.Pop();
	st.Pop();
	st.Print();

	Queue<int> qu(3);
	qu.Push(2);
	qu.Push(4);
	qu.Push(6);
	qu.Print();
	qu.Pop();
	qu.Pop();
	qu.Print();
	return;
}