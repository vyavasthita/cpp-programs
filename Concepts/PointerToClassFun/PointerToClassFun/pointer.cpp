#include "pointer.h"

int CPointer::addNum(int a, int b)
{
	return a + b;
}

void main()
{
	int (CPointer::*ptr)(int, int) = &CPointer::addNum;

}