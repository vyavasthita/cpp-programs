#include "Ford.h"

CFord::CFord()
{
}

std::string CFord::carInfo()
{
	std::string strCarInfo = "This is a Ford Car";
	return strCarInfo;
}

int CFord::getPrice()
{
	return 500000;
}

std::string CFord::getMusicSystem()
{
	std::string strCarInfo = "Ford's music system";
	return strCarInfo;
}

void CFord::powerSteering()
{
	std::cout << "Ford's power steering system";
}