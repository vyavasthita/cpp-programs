#include <iostream>
#include <conio.h>

using namespace std;


class Base
{
   	public:
      	Base()
		{ 
			cout<<"Constructing Base\n";
		}
      	
     // this is a destructor:
	
		virtual ~Base()
		{ 
			cout<<"Destroying Base\n";
		}
};

class Derived: public Base
{
    public:
    Derived()
	{ 
		cout<<"Constructing Derived\n";
	}
       	
    virtual ~Derived()
	{ 
		cout<<"Destroying Derived\n";
	}
 };

void main()
{
	{
		Base *obj = new Base;
		//delete obj;
	}
	getch();
}