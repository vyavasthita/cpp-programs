#include <iostream>
#include "Car.h"
#include "Factory.h"

#ifndef __LAND_ROVER_FACTORY_H_
#define __LAND_ROVER_FACTORY_H_

namespace FactoryPattern
{
	class CLandRoverFactory : public CFactory
	{
		public:
			virtual CCar* BuildCar();
	};
};

#endif __LAND_ROVER_FACTORY_H_