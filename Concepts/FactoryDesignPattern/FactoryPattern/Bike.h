#ifndef __BIKE_H_
#define __BIKE_H_

#include <iostream>

namespace FactoryPattern
{
	class CBike
	{
		public:
			virtual std::string BikeInfo() = 0;
	};
};

#endif __BIKE_H_