#include "PizzaBuilder.h"
#include <iostream>
#include <conio.h>

using namespace std;

void main()
{
	cout<<"Pizza Details are given below : \n\n";

	cout<<PizzaBuilderContext::buildPizza(PizzaType::CHEEZ)->getInfo().c_str();
	cout<<" with Price ";
	cout<<PizzaBuilderContext::buildPizza(PizzaType::CHEEZ)->getPrice()<<endl;

	cout<<PizzaBuilderContext::buildPizza(PizzaType::CAPSICUM)->getInfo().c_str();
	cout<<" with Price ";
	cout<<PizzaBuilderContext::buildPizza(PizzaType::CAPSICUM)->getPrice()<<endl;

	cout<<PizzaBuilderContext::buildPizza(PizzaType::TOMATO)->getInfo().c_str();
	cout<<" with Price ";
	cout<<PizzaBuilderContext::buildPizza(PizzaType::TOMATO)->getPrice()<<endl;

	getch();
}