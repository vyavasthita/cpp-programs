#include "operator.h"
#include <conio.h>


void main()
{
	COpOverloading ob1(5);
	//COpOverloading ob2(7, 5);

	COpOverloading ob3 = 10 + ob1;

	ob3.printData();

	getch();
}