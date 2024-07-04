#ifndef _CAR__H_
#define _CAR__H_

namespace Vehicle
{
	class Car
	{
		public:
			virtual const char* getCarName() = 0;
	};

	class BasicCar : public Car
	{
		public:
			virtual const char* getCarName();
	};
	class LuxuryCar : public Car
	{
		public:
			virtual const char* getCarName();
	};
	class SuperLuxuryCar : public Car
	{
		public:
			virtual const char* getCarName();
	};
};


#endif _CAR__H_ 
