#include <iostream>
#include <conio.h>

using namespace std;


class Base
{
	public:
		virtual void overridefun()
		{
			cout << "Base override fun\n";
		}
};

class Derived : public Base
{
	protected://differenet access specifier
		virtual void overridefun() 
		{
			cout << "Derived override fun\n";
		}
};

class Derived1 : public Derived
{
	public:
		void myfun();	
};

void Derived1::myfun()
{
	Derived d;
	//d.overridefun(); //errr : because only classes which inherit Derived class can use protected members of Derived class

	Base& ref = d;
	ref.overridefun(); // protected access can not be enforced completely if Base class makes that method public
}

void main()
{
	{
		//Derived d;
		////d.overridefun(); //errr : because only classes which inherit Derived class can use protected members of Derived class

		//Base& ref = d;
		//ref.overridefun(); // protected access can not be enforced completely if Base class makes that method public
	}
	Derived1 d1;
	d1.myfun();
	getch();
}