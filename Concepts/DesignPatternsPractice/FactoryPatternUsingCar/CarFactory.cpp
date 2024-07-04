#include "CarFactory.h"

using namespace Vehicle;


Car* CarFactory::getCarObject(TYPE carType)
{
	switch (carType)
	{
		case BASIC:
			m_Car = new BasicCar;
			break;
		case LUXURY:
			m_Car = new LuxuryCar;
			break;
		case SUPER_LUXURY:
			m_Car = new SuperLuxuryCar;
			break;
		default:
			break;
	}
	return m_Car;
}

CarFactory::~CarFactory()
{
	delete m_Car;
}