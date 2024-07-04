#include "LandRoverFactory.h"
#include "LandRoverCar.h"


using namespace FactoryPattern;

CCar* CLandRoverFactory::BuildCar()
{
	return new CLandRoverCar();
}