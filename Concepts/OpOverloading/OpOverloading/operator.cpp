#include "operator.h"

COpOverloading::COpOverloading()
{
}

COpOverloading::COpOverloading(int i)
{
	a = i;
	//b = j;
}

COpOverloading operator+(const COpOverloading& lhs, const COpOverloading& rhs)
{
	COpOverloading temp;

	temp.a = lhs.a + rhs.a;
	//temp.b = lhs.b + rhs.b;

	return temp;
}

void COpOverloading::printData()
{
	std::cout << "a = "<< a << std::endl;
	//std::cout << "b = "<< b << std::endl;
}