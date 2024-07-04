#include "ToyotaCar.h"
#include "ToyotaBike.h"
#include "ToyotaFactory.h"
#include "FordCar.h"
#include "FordBike.h"
#include "FordFactory.h"
#include "ToyotaTruck.h"
#include <conio.h>

using namespace FactoryPattern;

void main()
{
	CCar *poCar = NULL;
	CBike *poBike = NULL;
	CFactory *poFactory = NULL;

	poFactory = new CFordFactory;
	poCar = poFactory->BuildCar();

	std::cout << poCar->CarInfo().c_str() << std::endl;

	poBike = poFactory->BuildBike();
	std::cout << poBike->BikeInfo().c_str() << std::endl; 

	getch();
}