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

		virtual ~Base()
		{
			cout << "Base Dtor\n";
		}
};

class Derived : public Base
{
	public:
		Derived()
		{
			cout << "Derived Ctor\n";
		}

		virtual ~Derived()
		{
			cout << "Derived Dtor\n";
		}
};

class Derived2 : public Derived
{
	public:
		Derived2()
		{
			cout << "Derived2 Ctor\n";
		}

		virtual ~Derived2()
		{
			cout << "Derived2 Dtor\n";
		}
};

void main()
{
	{
		Derived* d = new Derived2;

		delete d;
	}
		getch();

}