#include "sort.h"
#include <conio.h>

int main()
{
	CMergeSort oCMergeSort;
	oCMergeSort.userConsole();

	oCMergeSort.mergeSort();
	oCMergeSort.printArray();

	getch();
	return 1;
}