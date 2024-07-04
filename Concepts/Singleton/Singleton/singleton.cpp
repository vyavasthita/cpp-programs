#include "singleton.h"

CSingleton* CSingleton::singletonObject = NULL;
int CSingleton::var = 7;


CSingleton* CSingleton::getInstance()
{
	if (singletonObject == NULL)
	{
		std::cout << "getInstance\n";
		singletonObject = new CSingleton;
	}
	return singletonObject;
}

CSingleton::CSingleton()
{
}

CSingleton::~CSingleton()
{
	delete singletonObject;
	singletonObject = NULL;
}

void CSingleton::singletonFunction()
{
	var++;
	std::cout << "This is a singleton fun, var value is : "<< var << "\n";
}