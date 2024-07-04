#include <iostream>
#include "ComputerFactory.h"
#include "Desktop.h"
#include "Laptop.h"

#ifndef _DELL_FAC_H_
#define _DELL_FAC_H_

namespace Electronics
{
	class CDellFactory: public CComputerFactory
	{
		public:
			virtual CLaptop* CreateLaptop();
			virtual CDesktop* CreateDesktop();
	};
};

#endif _DELL_FAC_H_