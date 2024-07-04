#ifndef __PIZZA_H_
#define __PIZZA_H_

#include <iostream>

class PizzaContext
{
	public:
		virtual std::string getInfo() = 0;
		virtual int getPrice() const = 0;
};

#endif __PIZZA_H_