#include <iostream>
#include "ComputerFactory.h"
#include "Desktop.h"
#include "Laptop.h"

#ifndef _HCL_FAC_H_
#define _HCL_FAC_H_

namespace Electronics
{
	class CHCLFactory: public CComputerFactory
	{
		public:
			virtual CLaptop* CreateLaptop();
			virtual CDesktop* CreateDesktop();
	};
};

#endif _HCL_FAC_H_