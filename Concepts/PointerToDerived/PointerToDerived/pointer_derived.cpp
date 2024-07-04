#include <iostream>
#include <conio.h>
#include <list>
using namespace std;

class Base
{
	public:
		int i;
		virtual void bas()
		{
			cout<<"Base\n";
		}
};

class Derived:public Base
{
	public:
		int j;
		void bas()
		{
			cout<<"Base in Derived\n";
		}
		void der()
		{
			cout<<"Derived\n";
		}
};
void main()
{
	Base b;
	Base* bp, *bp2;
	Derived d;
	Derived *dp;

	bp = &d;
	
	dp = dynamic_cast<Derived*>(bp);
	
	getch();
}