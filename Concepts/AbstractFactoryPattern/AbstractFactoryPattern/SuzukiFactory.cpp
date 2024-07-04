#include "SuzukiFactory.h"

CCar* CSuzukiFactory::MakeCar()
{
	return new CSuzukiCar();
}

CBike* CSuzukiFactory::MakeBike()
{
	return new CSuzukiBike();
}