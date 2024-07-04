#include "Car.h"

#ifndef _BASIC_CAR__H_
#define _BASIC_CAR__H_

namespace Vehicle
{
	class BasicCar : public Car
	{
		public:
			virtual const char* getCarType();
	};
};


#endif _BASIC_CAR__H_

