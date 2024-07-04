#include "FordFactory.h"
#include "FordCar.h"
#include "FordBike.h"

using namespace FactoryPattern;

CCar* CFordFactory::BuildCar()
{
	return new CFordCar;
}

CBike* CFordFactory::BuildBike()
{
	return new CFordBike;
}