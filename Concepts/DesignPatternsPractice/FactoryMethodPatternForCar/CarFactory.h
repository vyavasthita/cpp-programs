#include "Car.h"


#ifndef _CAR_FACTORY__H_
#define _CAR_FACTORY__H_


namespace Vehicle
{
	class CarFactory
	{
		public:
			virtual Car* getCar() = 0;
			const char* requestCar();
	};

	class BasicCarFactory : public CarFactory
	{
		public:
			virtual Car* getCar();
	};

	class LuxuryCarFactory : public CarFactory
	{
		public:
			virtual Car* getCar();
	};
	class SuperLuxuryCarFactory : public CarFactory
	{
		public:
			virtual Car* getCar();
	};
};


#endif _CAR_FACTORY__H_ 
