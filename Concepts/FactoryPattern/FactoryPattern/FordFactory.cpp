#include "FordFactory.h"
#include "FordCar.h"

CCar* CFordFactory::CreateCar()
{
	return new CFord;
}

CBike* CFordFactory::CreateBike()
{
	return new CFordBike;
}