#ifndef __PIZZA_BUILDER_H_
#define __PIZZA_BUILDER_H_

#include "CapsicumPizza.h"
#include "CheezPizza.h"
#include "TomatoPizza.h"

enum PizzaType
{
	CHEEZ = 1,
	CAPSICUM,
	TOMATO
};

class PizzaBuilderContext
{
	public:
		static PizzaContext* buildPizza(PizzaType type);
};

#endif __PIZZA_BUILDER_H_