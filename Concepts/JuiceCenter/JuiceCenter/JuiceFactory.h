#include <iostream>

#ifndef __JUICE_FACTORY
#define __JUICE_FACTORY

class CJuiceFactory
{
	public:
		virtual std::string MakeJuice() = 0;
};

#endif __JUICE_FACTORY