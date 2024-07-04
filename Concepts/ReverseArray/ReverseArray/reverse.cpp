#include "reverse.h"


CReverse::CReverse()
{
}

CReverse::~CReverse()
{
	delete [] rev;
	rev = NULL;
}


void CReverse::userConsole()
{
	int element = 0;

	std::cout << "Enter array size -->" << std::endl;

	std::cin >> size;

	rev = new int[size];

	for (int i = 0; i < size; i++)
	{
		std::cout << "Enter element " << i + 1 << "--> ";
		std::cin >> element;

		rev[i] = element;
	}
}

void CReverse::reverseArray()
{
	for (int i = 0; i < size/2 + 1; i++)
	{
		swapValues(rev[i], rev[size - 1 - i]);
	}
}

void CReverse::printValues()
{
	std::cout << "\n";

	for (int i = 0; i < size; i++)
	{
		std::cout << "Element " << i + 1 << "--> ";
		std::cout << rev[i] << std::endl;
	}
	std::cout << "\n";
}

void CReverse::swapValues(int& a, int &b)
{
	if (a == b)
		return;

	int temp = 0;

	temp = a;
	a = b;
	b = temp;
}