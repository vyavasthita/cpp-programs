#include <iostream>
#include <conio.h>

using namespace std;


class Base
{
	public:
		virtual void meth()
		{
			cout<<"Base"<<endl;
		}
};

class Derived:public Base
{
	public:
		void meth()
		{
			cout<<"Derived"<<endl;
		}
};


void main()
{
	Base * ptr;
	Derived d;
	ptr = &d;
	ptr->meth();
	getch();
	
}