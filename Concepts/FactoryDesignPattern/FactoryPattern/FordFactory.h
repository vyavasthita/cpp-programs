#ifndef __FORD_FACT_H_
#define __FORD_FACT_H_

#include "Factory.h"

namespace FactoryPattern
{
	class CFordFactory : public CFactory
	{
		public:
			virtual CCar* BuildCar();
			virtual CBike* BuildBike();
	};
};

#endif __FORD_FACT_H_