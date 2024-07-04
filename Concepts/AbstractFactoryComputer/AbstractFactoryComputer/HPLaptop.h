#include <iostream>
#include "Laptop.h"

#ifndef __HP_LAP_H_
#define __HP_LAP_H_

namespace Electronics
{
	class CHPLaptop : public CLaptop
	{
		public:
			virtual void info();
	};
};

#endif __HP_LAP_H_