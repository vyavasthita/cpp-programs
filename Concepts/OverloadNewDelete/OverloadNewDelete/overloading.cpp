#include "overloading.h"
#include <conio.h>


void* MyOperator::operator new(size_t size)
{
	std::cout << "Size is " << size << std::endl;

	MyOperator* ptr = (MyOperator*)malloc(sizeof(MyOperator));

	return ptr;
}

void MyOperator::operator delete(void* ptr)
{
	free(ptr);
}

void main()
{
	MyOperator* obj = new MyOperator;

	delete obj;

	getch();
}