#include "Car.h"

#ifndef _LUXURY_CAR__H_
#define _LUXURY_CAR__H_

namespace Vehicle
{
	class LuxuryCar : public Car
	{
		public:
			virtual const char* getCarType();
	};
};


#endif _LUXURY_CAR__H_

