#ifndef __FORD_FACT_
#define __FORD_FACT_

#include "Factory.h"
#include "FordBike.h"
#include <iostream>


class CFordFactory:public CCarFactory
{
	public:
		virtual CCar* CreateCar();
		virtual CBike* CreateBike();
};

#endif __FORD_FACT_