#include "Car.h"
#include "BasicCar.h"
#include "LuxuryCar.h"
#include "SuperLuxury.h"


#ifndef _CAR_FACTORY__H_
#define _CAR_FACTORY__H_


namespace Vehicle
{
	typedef enum CAR_TYPE
	{
		BASIC = 1,
		LUXURY = 2,
		SUPER_LUXURY = 3
	}TYPE;

	class CarFactory
	{
		public:
			Car* getCarObject(TYPE carType);
			~CarFactory();
		private:
			Car* m_Car;
	};
};


#endif _CAR_FACTORY__H_ 
