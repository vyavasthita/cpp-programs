#ifndef __TOMATO_PIZZA_H_
#define __TOMATO_PIZZA_H_

#include "Pizza.h"

class Tomato : public PizzaContext
{
	public:
		virtual std::string getInfo();
		virtual int getPrice() const;
};

#endif __TOMATO_PIZZA_H_