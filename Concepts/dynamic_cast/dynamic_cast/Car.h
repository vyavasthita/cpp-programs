#include <iostream>

#ifndef __CAR_H_
#define __CAR_H_


class CCar
{
	public:
		virtual std::string carInfo() = 0;
		virtual int getPrice() = 0;		
};

#endif __CAR_H_