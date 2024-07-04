#include "HondaFactory.h"
#include "HondaBike.h"
#include "HondaCar.h"

CCar* CHondaFactory::MakeCar()
{
	return new CHondaCar();
}

CBike* CHondaFactory::MakeBike()
{
	return new CHondaBike();
}