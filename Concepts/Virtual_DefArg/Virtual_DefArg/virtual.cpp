#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

class Base
{
public:
    virtual void Func(bool state = true)
    {
        std::cout << "Base called: " << std::boolalpha << state << "\n";
    }
};

class Derived : public Base
{
public:
    virtual void Func(bool state = false)
    {
        std::cout << "Derived called: " << std::boolalpha << state << "\n";
    }
};


int main()
{
    Derived d;
    d.Func();       // "Derived called: false"
                    // Derived::Func is called, and Derived::Func's default
                    //  param is used because 'd' is of type Derived

    Base* b = &d;
    b->Func();      // "Derived called: true"
                    // Derived::Func is called (because it's virtual)
                    //  but Base::Func's default param is used because 'b'
                    //  is of type Base*.  To the compiler, 'b' might not
                    //  be a Derived.  That distiction is made at runtime.
	getch();

    return 0;
}
