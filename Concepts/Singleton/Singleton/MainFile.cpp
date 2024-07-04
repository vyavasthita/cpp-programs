#include "singleton.h"
#include <conio.h>

void main()
{
	CSingleton* ptr = CSingleton::getInstance();
	ptr->singletonFunction();

	CSingleton* ptr1 = CSingleton::getInstance();
	ptr1->singletonFunction();

	CSingleton* ptr2 = CSingleton::getInstance();
	ptr2->singletonFunction();

	CSingleton* ptr3 = CSingleton::getInstance();
	ptr3->singletonFunction();

	CSingleton* ptr4 = CSingleton::getInstance();
	ptr4->singletonFunction();

	getch();
}