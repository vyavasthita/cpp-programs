#include "addition.h"

extern "C"
{
	int CAddition::addNum(int a, int b)
	{
		return a + b;
	}
}