#include "ToyotaFactory.h"
#include "ToyotaCar.h"
#include "ToyotaBike.h"
#include "ToyotaTruck.h"
#include "Truck.h"

using namespace FactoryPattern;

CCar* CToyotaFactory::BuildCar()
{
	return new CToyotaCar;
}

CBike* CToyotaFactory::BuildBike()
{
	return new CToyotaBike;
}

CTruck* CToyotaFactory::BuildTruck()
{
	return new CToyotaTruck;
}