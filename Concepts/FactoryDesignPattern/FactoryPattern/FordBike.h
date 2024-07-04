#ifndef __FORD_BIKE_H_
#define __FORD_BIKE_H_

#include "Bike.h"

using namespace FactoryPattern;

namespace FactoryPattern
{
	class CFordBike : public CBike
	{
		public:
			virtual std::string BikeInfo();
	};
};

#endif __FORD_BIKE_H_