#include "LandRoverCar.h"

using namespace FactoryPattern;

const char* CLandRoverCar::getCarInfo()
{
	return "This is a Land Rover Car";
}

long CLandRoverCar::getCarPrice()
{
	return 2000000;
}