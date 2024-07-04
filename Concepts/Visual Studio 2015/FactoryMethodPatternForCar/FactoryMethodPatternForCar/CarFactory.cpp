#include "Car.h"
#include "CarFactory.h"

using namespace Vehicle;

const char* CarFactory::requestCar()
{
	Car* car = this->getCar();
	return car->getCarName();
}

Car* BasicCarFactory::getCar()
{
	return new BasicCar();
}

Car* LuxuryCarFactory::getCar()
{
	return new LuxuryCar();
}

Car* SuperLuxuryCarFactory::getCar()
{
	return new SuperLuxuryCar();
}