#include "../include/myheader.h"

const int TestNamespace::MyClass::no_of_employees = 10;

namespace TestNamespace
{
    MyClass::MyClass(): mAge(0)
    {
        std::cout << "Ctor is called " << no_of_employees << std::endl;
    }
    
    MyClass::MyClass(int age): mAge(age)
    {
        std::cout << "Ctor is called with age => " << mAge << std::endl;
    }

    MyClass::~MyClass()
    {
        std::cout << "Dtor is called." << std::endl;
    }

    const MyClass MyClass::operator + (const MyClass & ob)
    {
        MyClass temp;
        temp.mAge = mAge + ob.mAge;
        return temp;
    }

    void MyClass::someMeth() const
    {
    }


    int MyClass::sub(int a, int b)
    {
        return a - b;
    }

    int add(int a, int b)
    {
        return a + b;
    }
}