#include "fpointer.h"
#include <conio.h>


void main()
{
	int (CPointer::*fptr)(int, int) = &CPointer::addNum;

	std::cout << (fptr)(5, 7);
}