#include <iostream>
#include <conio.h>
#include <string>
#include "ComputerFactory.h"
#include "Desktop.h"
#include "Laptop.h"

using namespace Electronics;


int main()
{
	CComputerFactory* oCComputerFactory1 = CComputerFactory::CreateFactory(CComputerFactory::COMPUTER_FACTORIES::HP);

	CDesktop* oCDesktop = oCComputerFactory1->CreateDesktop();

	oCDesktop->info();

	CComputerFactory* oCComputerFactory2 = CComputerFactory::CreateFactory(CComputerFactory::COMPUTER_FACTORIES::HP);

	CLaptop* oCLaptop = oCComputerFactory2->CreateLaptop();

	oCLaptop->info();

	getch();

	return 1;
}