#include <conio.h>
#include "singleton.h"

int main()
{
	CSingleton::getInstance()->fun();
	CSingleton::getInstance()->fun();
	CSingleton::getInstance()->fun();

	getch();
}