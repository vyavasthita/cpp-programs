#include "smart.h"
#include <conio.h>

using namespace NamespaceSmartPointerForInt;

int main()
{
	{
		int* ptr = new int;

		SmartPointerForInt sp(ptr);		// Count = 1
		SmartPointerForInt sp2(sp);	// Count = 1
		SmartPointerForInt sp3(sp2);	// Count = 2

		SmartPointerForInt sp4 = new int;

		SmartPointerForInt sp5;

		sp5 = sp4;

		sp.release();	// Count = 0
	}
	_getch();
}