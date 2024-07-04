#include "reverse.h"
#include <conio.h>

void main()
{
	CReverse ob;

	ob.userConsole();

	std::cout << "Before Reverse -->" << std::endl;
	ob.printValues();

	ob.reverseArray();

	std::cout << "After Reverse -->" << std::endl;
	ob.printValues();

	getch();
}