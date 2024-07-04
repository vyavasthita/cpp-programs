#ifndef __VEH_FACT_H
#define __VEH_FACT_H

#include "Car.h"
#include "Bike.h"

class CVehicleFactory
{
	public:
		virtual CCar* MakeCar() = 0;
		virtual CBike* MakeBike() = 0;
};

#endif __VEH_FACT_H