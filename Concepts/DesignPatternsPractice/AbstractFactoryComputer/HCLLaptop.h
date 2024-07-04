#include <iostream>
#include "Laptop.h"

#ifndef __HCL_LAP_H_
#define __HCL_LAP_H_

namespace Electronics
{
	class CHCLLaptop : public CLaptop
	{
		public:
			virtual void info();
	};
};

#endif __HCL_LAP_H_