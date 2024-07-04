#ifndef __HONDA_FACT_H
#define __HONDA_FACT_H

#include "VechicleFactory.h"

class CHondaFactory : public CVehicleFactory
{
	public:
		virtual CCar* MakeCar();
		virtual CBike* MakeBike();
};

#endif __HONDA_FACT_H