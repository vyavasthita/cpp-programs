#include <iostream>
#include <conio.h>
#include <memory>

using namespace std;


class Base
{
	static Base * bptr;
	static int count;
	Base* getInstance()
	{
		if(count == 0)
		{
			bptr = new Base;
		}
		return bptr;
	}
	~Base()
	{
		--count;
		delete bptr;
		cout<<"Destroying Base"<<endl;
	}
	
    Base()
	{ 
		cout<<"Constructing Base"<<endl;
	}	
};

int Base::count = 0;
Base * Base::bptr = NULL;

void main()
{
	Base *obj;
	getch();
}