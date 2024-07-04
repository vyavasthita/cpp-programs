#include "observer.h"
#include <iostream>

RamComputers::RamComputers()
{
	m_nProfit = 5000;
}

void RamComputers::update(int basePrice)
{
	m_nPrice = basePrice + m_nProfit;
	std::cout << "Laptop price by Ram Computers is --> " << m_nPrice << std::endl;
}

/////////////////////////

RahimComputers::RahimComputers()
{
	m_nProfit = 4500;
}

void RahimComputers::update(int basePrice)
{
	m_nPrice = basePrice + m_nProfit;
	std::cout << "Laptop price by Rahim Computers is --> " << m_nPrice << std::endl;
}