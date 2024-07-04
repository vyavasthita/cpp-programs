#include <iostream>
#include <conio.h>
#include "VechicleFactory.h"
#include "SuzukiFactory.h"
#include "HondaFactory.h"
#include "Car.h"
#include "Bike.h"


void main()
{
	CVehicleFactory *factory;
	CCar *newCar;
	CBike *newBike;
	
	factory = new CSuzukiFactory();

	newCar = factory->MakeCar();
	newCar->CarName();

	newBike = factory->MakeBike();
	newBike->BikeName();

	factory = new CHondaFactory();

	newCar = factory->MakeCar();
	newCar->CarName();

	newBike = factory->MakeBike();
	newBike->BikeName();


	getch();
}