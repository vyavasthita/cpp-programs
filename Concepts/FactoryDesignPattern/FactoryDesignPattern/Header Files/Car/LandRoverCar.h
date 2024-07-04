#include <iostream>
#include "Car.h"

#ifndef __LAND_ROVER_CAR_H_
#define __LAND_ROVER_CAR_H_

namespace FactoryPattern
{
	class CLandRoverCar : public CCar
	{
		public:
			virtual const char* getCarInfo();
			virtual long getCarPrice();
	};
};

#endif __LAND_ROVER_CAR_H_