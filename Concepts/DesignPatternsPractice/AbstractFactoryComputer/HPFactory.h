#include <iostream>
#include "ComputerFactory.h"
#include "Desktop.h"
#include "Laptop.h"

#ifndef _HP_FAC_H_
#define _HP_FAC_H_

namespace Electronics
{
	class CHPFactory: public CComputerFactory
	{
		public:
			virtual CLaptop* CreateLaptop();
			virtual CDesktop* CreateDesktop();
	};
};

#endif _HP_FAC_H_