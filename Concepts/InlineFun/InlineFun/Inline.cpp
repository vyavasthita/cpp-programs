#include <iostream>
#include <conio.h>

using namespace std;

class MyClass
{
	public:
		void fun()
		{
			cout<<"This is a inline Fun";
		}
};

inline void inlineFun()
{
	cout<<"Inline Fun\n";
}

void main()
{
	inlineFun();

	MyClass obj;
	obj.fun();
	getch();
}