#include <iostream>
#include <conio.h>

using namespace std;

template <typename stackType> class stack
{
	int tos;
	stackType arr[10];

	public:
		stack()
		{
			tos = -1;
		}
		void push(stackType);
		stackType pop();
		void print();
};

template<typename stackType> void stack<stackType>::push(stackType item)
{
	if(tos == 10)
	{
		cout<<"Stack Overflow\n";
		return;
	}
	arr[++tos] = item;
}

template<typename stackType> stackType stack<stackType>::pop()
{
	if(tos == 0)
	{
		cout<<"Stack Underflow\n";
		return;
	}
	return arr[tos--];
}

template<typename stackType> void stack<stackType>::print()
{
	for(int i = 0; i <= tos; i++)
	{
		cout<<arr[tos]<<" ";
	}
}

void main()
{
	stack <int> ob;

	ob.push(1);
	ob.push(3);
	ob.print();

	getch();
}