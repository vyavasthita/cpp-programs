#include <iostream>
#include "Car.h"
#include "Factory.h"

#ifndef __MARUTI_FACTORY_H_
#define __MARUTI_FACTORY_H_

namespace FactoryPattern
{
	class CMarutiFactory : public CFactory
	{
		public:
			virtual CCar* BuildCar();
	};
};

#endif __MARUTI_FACTORY_H_