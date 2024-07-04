#include <iostream>
#include "ComputerFactory.h"
#include "DellFactory.h"
#include "DellDesktop.h"
#include "DellLaptop.h"

using namespace Electronics;


CLaptop* CDellFactory::CreateLaptop()
{
	return new CDellLaptop();
}

CDesktop* CDellFactory::CreateDesktop()
{
	return new CDellDesktop();
}