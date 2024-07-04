#ifndef __TOYO_BIKE_H_
#define __TOYO_BIKE_H_

#include "Bike.h"

using namespace FactoryPattern;

namespace FactoryPattern
{
	class CToyotaBike : public CBike
	{
		public:
			virtual std::string BikeInfo();
	};
};

#endif __TOYO_BIKE_H_