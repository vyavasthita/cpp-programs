#include "ComputerFactory.h"
#include "DellFactory.h"
#include "HCLFactory.h"
#include "HPFactory.h"

using namespace Electronics;


CComputerFactory* CComputerFactory::CreateFactory(COMPUTER_FACTORIES factory)
{
	if (factory == COMPUTER_FACTORIES::DELL)
	{
		return new CDellFactory();
	}
	else if(factory == COMPUTER_FACTORIES::HCL)
	{
		return new CHCLFactory();
	}
	else if(factory == COMPUTER_FACTORIES::HP)
	{
		return new CHPFactory();
	}
}