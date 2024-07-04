#include "sort.h"
#include <conio.h>

int main()
{
	CSelectionSort oCSelectionSort;
	oCSelectionSort.userConsole();

	oCSelectionSort.sort();
	oCSelectionSort.printArray();

	getch();
	return 1;
}