#include "MarutiCar.h"

using namespace FactoryPattern;

const char* CMarutiCar::getCarInfo()
{
	return "This is a Maruti Car";
}

long CMarutiCar::getCarPrice()
{
	return 200000;
}