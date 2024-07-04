#include "fpointer.h"

CPointer::CPointer()
{
}

CPointer::~CPointer()
{
}

int CPointer::addNum(int i, int j)
{
	return i + j;
}

void CPointer::otherFun(int (CPointer::*ptr)(int, int))
{
	(this->*ptr)(5, 7);
}