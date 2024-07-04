#include <iostream>
#include <conio.h>

using namespace std;

class myclass
{
	public:
		int fun(int, float);
		void pToFun(int (myclass::*ptr)(int, float));
};


int myclass::fun(int a, float b)
{
	cout<<"Function\n";
	return 1;
}

void myclass::pToFun(int (myclass::*ptr)(int, float))
{
	(this->*ptr)(5, 7);
}
void main()
{
	myclass obj;
	int (myclass::*p)(int, float) = &myclass::fun;
	obj.pToFun(p);
	getch();
}