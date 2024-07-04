#include <iostream>
#include "ComputerFactory.h"
#include "HCLFactory.h"
#include "HCLLaptop.h"
#include "HCLDesktop.h"

using namespace Electronics;


CLaptop* CHCLFactory::CreateLaptop()
{
	return new CHCLLaptop();
}

CDesktop* CHCLFactory::CreateDesktop()
{
	return new CHCLDesktop();
}