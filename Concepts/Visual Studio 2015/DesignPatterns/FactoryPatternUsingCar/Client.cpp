#include "Car.h"
#include "LuxuryCar.h"
#include "SuperLuxury.h"
#include "BasicCar.h"
#include "CarFactory.h"



#include <iostream>
#include <conio.h>

using namespace Vehicle;
using namespace std;

int main()
{

	CarFactory factory;
	Car* car;
	const char* carType = NULL;

	car = factory.getCarObject(BASIC);

	carType = car->getCarType();

	cout << carType << endl;

	car = factory.getCarObject(LUXURY);

	carType = car->getCarType();

	cout << carType << endl;

	car = factory.getCarObject(SUPER_LUXURY);

	carType = car->getCarType();

	cout << carType << endl;

	_getch();
	return 0;
}

