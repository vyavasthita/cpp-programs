#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

class Base
{
	public:
		int baseVar;
		void baseFun();
};

void Base::baseFun()
{
	cout<<"Inside Base's Function, baseVar is : "<<baseVar<<" ";
}

void main()
{
	int Base::*ptr;
	ptr = &Base::baseVar;

	Base obj;

	obj.*ptr = 10;
	
	void (Base::*fptr)() = &Base::baseFun;
	(obj.*fptr)();
	getch();
}