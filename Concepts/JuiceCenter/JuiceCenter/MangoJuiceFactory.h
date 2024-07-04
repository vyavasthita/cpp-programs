#include "JuiceFactory.h"

#ifndef __MANGO_JUICE_FACTORY
#define __MANGO_JUICE_FACTORY

class CMangoJuiceFactory : public CJuiceFactory
{
	public:
		virtual std::string MakeJuice();
	private:
		std::string strMangoJuice;
};

#endif __MANGO_JUICE_FACTORY