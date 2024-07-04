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
	private:
		virtual void overridefun()
		{
			cout << "Base override fun\n";
		}
		virtual void overridefu1n()
		{
			cout << "Base override1 fun\n";
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
		
		virtual void overridefun() 
		{
			cout << "Derived override fun\n";
		}
};

void main()
{
	{
		Derived d;
		d.overridefun();
	}
	getch();
}