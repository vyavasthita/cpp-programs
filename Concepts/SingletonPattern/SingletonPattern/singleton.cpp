#include "singleton.h"

CSingleton* CSingleton::getInstance()
{
	static CSingleton* oCSingleton;

	std::cout <<"Object created \n";

	return oCSingleton;
}

CSingleton::CSingleton()
{
	std::cout << "Ctor Called \n";
}

CSingleton::~CSingleton()
{
	std::cout << "Ctor Called \n";
}

void CSingleton::fun()
{
	std::cout << "fun Called \n";
}