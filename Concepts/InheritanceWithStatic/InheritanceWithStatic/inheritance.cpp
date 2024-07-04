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

		static void overridefun()
		{
			cout << "Base override fun\n";
		}
};

class Derived : public Base
{
	public:
		Derived()
		{
			cout << "Derived Ctor\n";
		}
		~Derived()
		{
			cout << "Derived Dtor\n";
		}
		//In c++ we can not override static method
		static void overridefun()// method in both the classes is different from each other...this is not overriding	
		{
			cout << "Derived override fun\n";
		}
};

void main()
{
	{
		Derived d;
		d.overridefun();
		Base::overridefun();
		Derived::overridefun();
	}
	getch();
}