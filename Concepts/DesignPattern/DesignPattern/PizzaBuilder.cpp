#include "PizzaBuilder.h"



PizzaContext* PizzaBuilderContext::buildPizza(PizzaType type)
{
	PizzaContext* pizzaContext = NULL;

	if(type == PizzaType::CHEEZ)
	{
		pizzaContext = new Cheez();
	}
	else if(type == PizzaType::CAPSICUM)
	{
		pizzaContext = new Capsicum();
	}
	else if(type == PizzaType::TOMATO)
	{
		pizzaContext = new Tomato();
	}
	return pizzaContext;
}