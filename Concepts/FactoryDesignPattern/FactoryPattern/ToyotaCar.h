#ifndef __TOYO_CAR_H_
#define __TOYO_CAR_H_

#include "Car.h"

using namespace FactoryPattern;

namespace FactoryPattern
{
	class CToyotaCar : public CCar
	{
		public:
			virtual std::string CarInfo();
	};
};

#endif __TOYO_CAR_H_