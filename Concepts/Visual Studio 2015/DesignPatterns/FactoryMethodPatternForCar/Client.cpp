#include "Car.h"
#include "CarFactory.h"
#include <iostream>
#include <conio.h>


using namespace Vehicle;


int main()
{
	CarFactory* factory = new SuperLuxuryCarFactory();

	//const char* carName = factory->requestCar();

	//std::cout << carName;

	_getch();
	return 0;
}