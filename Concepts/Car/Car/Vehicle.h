#include <conio.h>
#include "car.h"
#include "CreateObject.h"
#include <vector>

class Vehicle
{
	Car* basePtr;

	std::vector<Car*> vec;
	std::vector<Car*>::iterator it;

	public:
		Vehicle();
		void init();
		void Execute();
};