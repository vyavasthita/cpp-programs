#include "sample.h"
#include <memory>

void main()
{
	int *p = new int;
	auto_ptr<int> ptr(p);

	int*res = ptr.get();
	

	delete p;
	
	getch();
}