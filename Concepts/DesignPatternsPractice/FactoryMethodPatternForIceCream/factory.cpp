#include "factory.h"
#include "icecream.h"

IceCream* ChoclateIceCreamFactory::getProduct()
{
	return new ChoclateIceCream();
}

IceCream* VanillaIceCreamFactory::getProduct()
{
	return new VanillaIceCream();
}

IceCream* IceCreamFactory::getYourIceCream()
{
	return this->getProduct();
}