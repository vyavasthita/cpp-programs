#include <iostream>
#include <conio.h>

using namespace std;


class Base
{
	public:
		Base()
		{
			cout << "Base Ctor\n";
		}
		~Base()
		{
			cout << "Base Dtor\n";
		}

		virtual void overridefun()
		{
			cout << "Base override fun\n";
		}
};

class Derived1 : public Base
{
	public:
		Derived1()
		{
			cout << "Derived1 Ctor\n";
		}
		~Derived1()
		{
			cout << "Derived1 Dtor\n";
		}

		virtual void overridefun()
		{
			cout << "Derived1 override fun\n";
		}
};

class Derived2 : public Base
{
	public:
		Derived2()
		{
			cout << "Derived2 Ctor\n";
		}
		~Derived2()
		{
			cout << "Derived2 Dtor\n";
		}

		virtual void overridefun()
		{
			cout << "Derived2 override fun\n";
		}
};

class Derived3 : public Derived1, public Derived2
{
	public:
		Derived3()
		{
			cout << "Derived3 Ctor\n\n";
		}
		~Derived3()
		{
			cout << "Derived3 Dtor\n";
		}

		virtual void overridefun(int i)  // no method overriding here...
		{
			cout << "Derived3 override fun\n\n";
		}
};


void main()
{
	{
		Derived3 d3;
		d3.overridefun();		//will not compile because original method is hidden
		d3.Derived1::overridefun();
	}
	getch();
}