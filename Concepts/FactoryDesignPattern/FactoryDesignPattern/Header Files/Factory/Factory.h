#include <iostream>
#include "Car.h"

#ifndef __FACTORY_H_
#define __FACTORY_H_

namespace FactoryPattern
{
	class CFactory
	{
		public:
			virtual CCar* BuildCar() = 0;
	};
};

#endif __FACTORY_H_