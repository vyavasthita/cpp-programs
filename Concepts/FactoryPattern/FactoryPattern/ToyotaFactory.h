#ifndef __TOYT_FACT_
#define __TOYT_FACT_

#include "Factory.h"
#include "ToyotaBike.h"

class CToyotaFactory:public CCarFactory
{
	public:
		virtual CCar* CreateCar();
		virtual CBike* CreateBike();
};

#endif __TOYT_FACT_