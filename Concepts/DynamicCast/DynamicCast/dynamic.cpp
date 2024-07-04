#include <iostream>
#include <conio.h>
#include <typeinfo>

using namespace std;

class Base
{
	public:
		Base();
		virtual void fun1();
		virtual void fun2();
};

Base::Base()
{
	//cout << "Base Ctor\n";
}

void Base::fun1()
{
	cout << "Base fun1\n";
}
void Base::fun2()
{
	cout << "Base fun2\n";
}

class Derived : public Base
{
	public:
		Derived();
		virtual void fun1();
		virtual void fun3();
};

Derived::Derived()
{
	//cout << "Derived Ctor\n";
}

void Derived::fun1()
{
	cout << "Derived fun1\n";
}

void Derived::fun3()
{
	cout << "Derived fun3\n";
}

void main()
{
	Base b;
	Derived d;

	Base* bptr = new Base();
	Derived* dptr = new Derived();

	bptr = &d;

	//bptr->fun1();
	//bptr->fun2();

	//bptr = dynamic_cast<Base*>(dptr);
	dptr = dynamic_cast<Derived*>(bptr);

	if (bptr != NULL)
	{
		cout << "dynamic cast successfull\n";
	}
	else
	{
		cout << "dynamic cast un-successfull\n";
	}

	dptr->fun1();

	getch();
}
