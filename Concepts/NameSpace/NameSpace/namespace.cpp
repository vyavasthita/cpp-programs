#include "Namespace.h"
#include <conio.h>

using namespace myNameSpace;

void MyClass::myFun()
{
	std::cout<<"This is a Function\n";
}
void main()
{
	MyClass obj;
	obj.myFun();
	getch();
}