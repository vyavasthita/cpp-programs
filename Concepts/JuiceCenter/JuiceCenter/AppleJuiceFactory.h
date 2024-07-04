#include "JuiceFactory.h"

#ifndef __APPLE_JUICE_FACTORY
#define __APPLE_JUICE_FACTORY

class CAppleJuiceFactory : public CJuiceFactory
{
	public:
		virtual std::string MakeJuice();
	private:
		std::string strAppleJuice;
};

#endif __APPLE_JUICE_FACTORY