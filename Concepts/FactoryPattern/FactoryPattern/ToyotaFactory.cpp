#include "ToyotaFactory.h"
#include "ToyotaCar.h"

CCar* CToyotaFactory::CreateCar()
{
	return new CToyota;
}

CBike* CToyotaFactory::CreateBike()
{
	return new CToyotaBike;
}