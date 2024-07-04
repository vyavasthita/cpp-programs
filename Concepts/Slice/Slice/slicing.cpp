#include <iostream>
#include <conio.h>
#include <typeinfo>

using namespace std;

class Base
{
	public:
		Base();
		virtual void fun();
};

Base::Base()
{
	cout << "Base class Dtor\n";
}

void Base::fun()
{
	cout << "Base class fun\n";
}

class Derived : public Base
{
	public:
		Derived();
		void fun();
};

Derived::Derived()
{
	cout << "Derived class Dtor\n";
}

void Derived::fun()
{
	cout << "Derived class fun\n";
}

void main()
{
	Derived d;
	Base b = d;		//Slicing, d is converted to Base object.

	Base &b2 = d;	//No slicing

	b.fun();
	b2.fun();
	getch();
}