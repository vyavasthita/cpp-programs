#include "Car.h"

#ifndef _SUPER_LUXURY_CAR__H_
#define _SUPER_LUXURY_CAR__H_

namespace Vehicle
{
	class SuperLuxuryCar : public Car
	{
	public:
		virtual const char* getCarType();
	};
};


#endif _SUPER_LUXURY_CAR__H_

