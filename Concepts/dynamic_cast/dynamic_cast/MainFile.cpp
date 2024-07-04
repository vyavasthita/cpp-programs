#include <iostream>
#include <conio.h>
#include <string>
#include <typeinfo>

#include "Car.h"
#include "Ford.h"
#include "MarutiSuzuki.h"

void main()
{
	CMarutiSuzuki maruti;
	CCar* car = NULL;
	CFord *ford = new CFord;	

	car = ford;

	if (typeid(car) == typeid(maruti)) 
	{
		std::cout << "Same Type\n";
	}
	else
	{
		std::cout << "Diff Type\n";
	}

	ford = dynamic_cast<CFord*>(car);

	std::cout << ford->getPrice();

	getch();
}