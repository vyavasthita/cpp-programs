#include <iostream>
#include <string>
#include "../include/myheader.h"


using namespace std;
using namespace TestNamespace;


int* next(int *arrayOfInt)
{
    return ++arrayOfInt;
}

class Base
{
    public:
        void first();
};

class Sub: public Base
{
    public:
        void first();
};

int main()
{
    // int* (*funcPtrTwo)(int *intPtr);

    // funcPtrTwo = &next;

    // int a = 5;
    // int* ptr = &a;

    // int resultTwo = *funcPtrTwo(ptr);

    int (*addPtr)(int, int) = add;
    int add_res = addPtr(5, 7);

    std::cout << "Add Result = " << add_res << std::endl;

    int (MyClass::*subPtr)(int, int) = &MyClass::sub;
    
    MyClass ob;

    int sub_res = ob.*subPtr(15, 5);

    std::cout << "Sub Result = " << sub_res << std::endl;

    
    return 0;
}