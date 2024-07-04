#include "MarutiFactory.h"
#include "MarutiCar.h"


using namespace FactoryPattern;

CCar* CMarutiFactory::BuildCar()
{
	return new CMarutiCar();
}