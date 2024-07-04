#include "sort.h"
#include <conio.h>

int main()
{
	CInsertionSort oCInsertionSort;
	oCInsertionSort.userConsole();

	oCInsertionSort.sort();
	oCInsertionSort.printArray();

	getch();
	return 1;
}