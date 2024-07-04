#ifndef __CAR_FACT_
#define __CAR_FACT_

#include "Car.h"
#include "Bike.h"
#include <iostream>

class CCarFactory
{
	public:
		virtual CCar* CreateCar() = 0;
		virtual CBike* CreateBike() = 0;
};

#endif __CAR_FACT_