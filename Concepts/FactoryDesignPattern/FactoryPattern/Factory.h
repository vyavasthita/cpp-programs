#ifndef __FACT_H_
#define __FACT_H_

#include "Car.h"
#include "Bike.h"

namespace FactoryPattern
{
	class CFactory
	{
		public:
			virtual CCar* BuildCar() = 0;
			virtual CBike* BuildBike() = 0;
	};
};

#endif __FACT_H_