#include <iostream>
#include "Laptop.h"

#ifndef __DELL_LAP_H_
#define __DELL_LAP_H_

namespace Electronics
{
	class CDellLaptop : public CLaptop
	{
		public:
			virtual void info();
	};
};

#endif __DELL_LAP_H_