#include <iostream>
#include "Laptop.h"
#include "Desktop.h"

#ifndef _COMP_FAC_H_
#define _COMP_FAC_H_

namespace Electronics
{
	class CComputerFactory
	{
		public:
			enum COMPUTER_FACTORIES
			{
				DELL,
				HCL,
				HP
			};

			virtual CLaptop* CreateLaptop() = 0;
			virtual CDesktop* CreateDesktop() = 0;

			static CComputerFactory* CreateFactory(COMPUTER_FACTORIES factory);
	};

	
};

#endif _COMP_FAC_H_