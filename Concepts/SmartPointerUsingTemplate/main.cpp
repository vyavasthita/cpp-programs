#include "smart_temp.h"
#include <conio.h>

using namespace NamespaceSmartPointerWithTemp;

int main()
{
	{
		int* ptr = new int;

		SmartPointerWithTemp<int> sp(ptr);		// Count = 1		
		SmartPointerWithTemp<int> sp2(sp);	// Count = 1
		SmartPointerWithTemp<int> sp3(sp2);	// Count = 2
		SmartPointerWithTemp<int> sp4 = new int;
		SmartPointerWithTemp<int> sp5;

		sp5 = sp4;

		sp.release();	// Count = 0
	}
	_getch();
}