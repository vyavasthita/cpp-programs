#ifndef __SUZ_FACT_H
#define __SUZ_FACT_H

#include "VechicleFactory.h"
#include "SuzukiBike.h"
#include "SuzukiCar.h"

class CSuzukiFactory : public CVehicleFactory
{
	public:
		virtual CCar* MakeCar();
		virtual CBike* MakeBike();
};

#endif __SUZ_FACT_H