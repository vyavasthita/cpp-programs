#include <iostream>
#include <conio.h>

using namespace std;


class Base
{
	public:
		Base()
		{
			//cout << "Base Ctor\n";
		}
		~Base()
		{
			//cout << "Base Dtor\n";
		}

		virtual void overridefun()
		{
			cout << "Base override fun\n";
		}
		virtual void overridefun(int i)
		{
			cout << "Base override fun with int parameter\n";
		}
		virtual void othermethod()
		{
			cout << "Base othermethod\n";
		}
};

class Derived : public Base
{
	public:
		Derived()
		{
			//cout << "Derived Ctor\n";
		}
		~Derived()
		{
			//cout << "Derived Dtor\n";
		}

		//Here we have overridden method with no argument, so method with int argument will be hidden in Derived class
		virtual void overridefun() 
		{
			cout << "Derived override fun\n";
		}
};

void main()
{
	{
		Derived d;
		Base* ptr = &d;
		ptr->overridefun(5);
		//d.overridefun(5);	//error : because method with int argument is hidden because it is not overridden in derived class
		//d.othermethod();
	}
	getch();
}