#include <iostream>
#include "Car.h"

#ifndef __MARUTI_CAR_H_
#define __MARUTI_CAR_H_

namespace FactoryPattern
{
	class CMarutiCar : public CCar
	{
		public:
			virtual const char* getCarInfo();
			virtual long getCarPrice();
	};
};

#endif __MARUTI_CAR_H_