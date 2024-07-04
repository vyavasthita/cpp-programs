#include <iostream>
#include "Car.h"

#ifndef __MARUTI_SUZUKI_H_
#define __MARUTI_SUZUKI_H_


class CMarutiSuzuki : public CCar
{
	public:
		CMarutiSuzuki();
		virtual std::string carInfo();
		virtual int getPrice();
		virtual std::string getMusicSystem();
};

#endif __MARUTI_SUZUKI_H_