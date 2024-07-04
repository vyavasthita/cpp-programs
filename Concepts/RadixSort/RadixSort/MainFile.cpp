#include "sort.h"
#include <conio.h>

int main()
{
	CRadixSort oCRadixSort;
	oCRadixSort.userConsole();

	oCRadixSort.radixSort();
	oCRadixSort.printArray();

	getch();
	return 1;
}