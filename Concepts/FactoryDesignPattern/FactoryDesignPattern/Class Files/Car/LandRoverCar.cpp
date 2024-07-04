#include "LandRoverCar.h"

using namespace FactoryPattern;

const char* CLandRoverCar::getCarInfo()
{
	return "This is a Maruti Car";
}

long CLandRoverCar::getCarPrice()
{
	return 200000;
}