#include "smart.h"
#include <conio.h>

void main()
{
	int *ptr = new int;

	SmartPointer<int> sp(ptr);
}