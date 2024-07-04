#include <iostream>
#include <conio.h>

using namespace std;


class Base
{
	public:
		virtual void overridefun(int i = 5)
		{
			cout << "Base override fun with value : " << i  << endl;
		}
};

class Derived : public Base
{
	public:		
		//virtual void overridefun(int i = 7) //def aurguments are not inherited in C++
		//{
		//	cout << "Derived override fun with value : " << i << endl;
		//}
		virtual void overridefun() //def aurguments are not inherited in C++
		{
			cout << "Derived override fun with value : " << endl;
		}
};

void main()
{
	{
		Derived d;
		//d.overridefun();

		Base b;
		//b.overridefun();

		Base* ptr = &d;
		ptr->overridefun(); // dericed function will be called, but with def aurgument of base function
	}
	getch();
}