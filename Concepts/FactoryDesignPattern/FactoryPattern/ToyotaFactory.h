#ifndef __TOYO_FACT_H_
#define __TOYO_FACT_H_

#include "Factory.h"
#include "Truck.h"

namespace FactoryPattern
{
	class CToyotaFactory : public CFactory
	{
		public:
			virtual CCar* BuildCar();
			virtual CBike* BuildBike();
			virtual CTruck* BuildTruck();
	};
};

#endif __TOYO_FACT_H_