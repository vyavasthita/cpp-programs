#pragma once

#include "icecream.h"


class IceCreamFactory
{
	public:
		virtual IceCream* getProduct() = 0;

		static IceCream* getYourIceCream();
};

class ChoclateIceCreamFactory : public IceCreamFactory
{
	public:
		virtual IceCream* getProduct();
};

class VanillaIceCreamFactory : public IceCreamFactory
{
	public:
		virtual IceCream* getProduct();
};