#ifndef __CHEEZ_PIZZA_H_
#define __CHEEZ_PIZZA_H_

#include "Pizza.h"

class Cheez : public PizzaContext
{
	public:
		virtual std::string getInfo();
		virtual int getPrice() const;
};

#endif __CHEEZ_PIZZA_H_