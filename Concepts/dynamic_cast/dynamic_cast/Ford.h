#include <iostream>
#include "Car.h"

#ifndef __FORD_H_
#define __FORD_H_


class CFord : public CCar
{
	public:
		CFord();
		virtual std::string carInfo();
		virtual int getPrice();
		virtual std::string getMusicSystem();
		virtual void powerSteering();
};

#endif __FORD_H_