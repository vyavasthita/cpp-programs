#ifndef __FORD_CAR_H_
#define __FORD_CAR_H_

#include "Car.h"
#include <iostream>

using namespace FactoryPattern;

namespace FactoryPattern
{
	class CFordCar : public CCar
	{
		public:
			virtual std::string CarInfo();
	};
};

#endif __FORD_CAR_H_