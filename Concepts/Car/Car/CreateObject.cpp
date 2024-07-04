#include "CreateObject.h"

CreateInstance::CreateInstance()
{
}
CreateInstance::CreateInstance(std::string carType)
{
	makeObject(carType);
}

Car* CreateInstance::makeObject(std::string carType)
{
	if(carType.compare("Suzuki") == 0)
	{
		instance = new Suzuki;
	}
	else if(carType.compare("Accent") == 0)
	{
		instance = new Accent;
	}
	
	else if(carType.compare("Mercedez") == 0)
	{
		instance = new Mercedez;
	}
	else
	{

	}
	return instance;
}

