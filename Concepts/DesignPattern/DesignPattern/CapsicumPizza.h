#ifndef __CAPS_PIZZA_H_
#define __CAPS_PIZZA_H_

#include "Pizza.h"

class Capsicum : public PizzaContext
{
	public:
		virtual std::string getInfo();
		virtual int getPrice() const;
};

#endif __CAPS_PIZZA_H_