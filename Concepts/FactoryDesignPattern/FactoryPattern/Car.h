#ifndef __CAR_H_
#define __CAR_H_

#include <iostream>

namespace FactoryPattern
{
	class CCar
	{
		public:
			virtual std::string CarInfo() = 0;
	};
};

#endif __CAR_H_