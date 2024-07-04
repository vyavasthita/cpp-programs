#include "Car.h"
#include "Factory.h"
#include "MarutiCar.h"
#include "LandRoverCar.h"
#include "MarutiFactory.h"
#include "LandRoverFactory.h"

#include <conio.h>

using namespace FactoryPattern;

void main()
{
	CCar* oCar = NULL;
	CFactory* oFactory = NULL;
	CMarutiFactory* oMarutiFactory = new CMarutiFactory();
	CLandRoverFactory* oCLandRoverFactory = new CLandRoverFactory();

	oFactory = oMarutiFactory;

	oCar = oFactory->BuildCar();
	std::cout << oCar->getCarInfo() << std::endl;
	std::cout << oCar->getCarPrice() << std::endl;

	oFactory = oCLandRoverFactory;
	std::cout << oFactory->BuildCar()->getCarInfo() << std::endl;
	std::cout << oFactory->BuildCar()->getCarPrice() << std::endl;

	getch();
}