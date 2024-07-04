#ifndef __TRUCK_H_
#define __TRUCK_H_

#include <iostream>

namespace FactoryPattern
{
	class CTruck
	{
		public:
			virtual std::string TruckInfo() = 0;
	};
};

#endif __TRUCK_H_