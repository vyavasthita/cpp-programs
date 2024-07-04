#include "JuiceFactory.h"

#ifndef __ORANGE_JUICE_FACTORY
#define __ORANGE_JUICE_FACTORY

class COrangeJuiceFactory : public CJuiceFactory
{
	public:
		virtual std::string MakeJuice();
	private:
		std::string strOrangeJuice;
};

#endif __ORANGE_JUICE_FACTORY