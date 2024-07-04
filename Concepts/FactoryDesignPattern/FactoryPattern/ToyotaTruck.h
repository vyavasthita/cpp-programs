#ifndef __TOYO_TRUCK_H_
#define __TOYO_TRUCK_H_

#include "Truck.h"
#include <iostream>

using namespace FactoryPattern;

namespace FactoryPattern
{
	class CToyotaTruck : public CTruck
	{
		public:
			virtual std::string TruckInfo();
	};
};

#endif __TOYO_TRUCK_H_