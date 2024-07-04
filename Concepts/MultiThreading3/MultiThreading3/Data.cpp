#include "Data.h"
#include <iostream>

int CData::value1 = 1;
int CData::value2 = 1;

CData::CData(void)
{
}

CData::~CData(void)
{
}

void CData::printData(const char* pcThreadName)
{
	std::cout << "Thread " << pcThreadName << " :printing first value to " << value1++ << std::endl;
	std::cout << "Thread " << pcThreadName << " :printing second value to " << value2++ << std::endl;
}
