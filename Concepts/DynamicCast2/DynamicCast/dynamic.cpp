#include <iostream>
#include <conio.h>
#include <typeinfo>

using namespace std;

//runtime-type information is stored in the vtable of the object. Therefore, in order to use
//dynamic_cast, your classes must have at least one virtual function.

#include <iostream>
using namespace std;
class Base
{
	public:
		Base() 
		{
		};
		virtual ~Base()
		{
		}
};

class Derived : public Base
{
	public:
		Derived()
		{
		}
		virtual ~Derived() 
		{
		}
};
int main(int argc, char** argv)
{
	Base* b;
	Derived* d = new Derived();
	
	b = d;

	if (typeid(b) == typeid(d))
	{
		cout << "same type\n";
	}
	else
	{
		cout << "diff type\n";
	}
	

	d = dynamic_cast<Derived*>(b);

	Base base;

	Derived derived;

	Base& br = base;

	try 
	{
		Derived& dr = dynamic_cast<Derived&>(br);
	} 
	catch (bad_cast&) 
	{
		cout << "Bad cast!\n";
	}

	getch();
	return (0);
}