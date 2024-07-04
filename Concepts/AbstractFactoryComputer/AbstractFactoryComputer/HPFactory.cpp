#include <iostream>
#include "ComputerFactory.h"
#include "HPFactory.h"
#include "HPDesktop.h"
#include "HPLaptop.h"

using namespace Electronics;


CLaptop* CHPFactory::CreateLaptop()
{
	return new CHPLaptop();
}

CDesktop* CHPFactory::CreateDesktop()
{
	return new CHPDesktop();
}