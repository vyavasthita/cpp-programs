#include <iostream>
#include <exception>
#include <conio.h>
#include <sstream>
#include <string>

using namespace std;

class MyClass
{
	public:
		MyClass();
		~MyClass();
		void clean();
	private:
		int* ptr;
};

MyClass::MyClass()
{
	ptr = new int[5];
	//when ctor throws an exception, dtor does not get called.
	throw "throwing exception";
}

MyClass::~MyClass()
{
	cout << "Dtor Called\n";

	clean();
}

void MyClass::clean()
{
	cout << "Inside Clean method\n";

	if (ptr != NULL)
	{
		delete [] ptr;
		ptr = NULL;
	}
}

void main()
{
	try
	{
		MyClass ob;
	}
	catch(char* str)
	{
		cout << "Exception caught in ctor";
	}
	catch(std::out_of_range e)
	{
		cout << "Exception caught in out of range\n";
		//clean();
	}
	catch(...)
	{
		cout << "Exception caught : default\n";
		//clean();
	}

	getch();
}