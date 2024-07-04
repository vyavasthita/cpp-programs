#include <iostream>
#include <conio.h>

using namespace std;
/*
If your subclass does not have any special data (pointers, usually) that require a nondefault copy constructor
or operator=, you don’t need to have one, regardless of whether or not the superclass has one.

If your subclass omits the copy constructor, the parent copy constructor will still be called when the
object is copied. Similarly, if you don’t provide an explicit operator=, the default one will be used, and
operator= will still be called on the parent class.

On the other hand, if you do specify a copy constructor in the subclass, you need to explicitly chain to
the parent copy constructor, as shown in the following code.

If you do not do this, the default constructor
(not the copy constructor!) will be used for the parent portion of the object.
*/

class Base
{
	public:
		void overridefun()
		{
			cout << "Base method\n";
		}
};

class Derived : public Base
{
	public:
		void overridefun()
		{
			cout << "Derived method\n";
		}
};

void main()
{	
	Derived d;
	Base& b = d;
	b.overridefun();
	getch();
}