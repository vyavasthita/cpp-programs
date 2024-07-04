#include "sort.h"
#include <conio.h>

int main()
{
	CBubbleSort oCBubbleSort;
	oCBubbleSort.userConsole();

	oCBubbleSort.sort();
	oCBubbleSort.printArray();

	getch();
	return 1;
}