#include "sort.h"
#include <conio.h>

int main()
{
	CBucketSort oCBucketSort;
	oCBucketSort.userConsole();

	oCBucketSort.sort();
	oCBucketSort.printArray();

	getch();
	return 1;
}