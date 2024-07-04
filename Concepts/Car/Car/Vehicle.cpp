#include "Vehicle.h"
#include <typeinfo>
#include <vector>
#include <string>

Vehicle::Vehicle()
{
	
}

void Vehicle::init()
{
	std::vector<std::string> car(3);
	std::vector<std::string>::iterator iter;

	car[0] = "Suzuki";
	car[1] = "Accent";
	car[2] = "Mercedez";

	iter = car.begin();
	
	CreateInstance ins;	 

	for(iter; iter != car.end(); iter++)
	{ 		
		basePtr = ins.makeObject(*iter);
		vec.push_back(basePtr);
	}
}

void Vehicle::Execute()
{
	it = vec.begin();
	for( it; it != vec.end(); it++)
	{		
		(*it)->design();
	} 
}

void main()
{
	Vehicle ob;
	ob.init();
	ob.Execute();
	getch();
}

