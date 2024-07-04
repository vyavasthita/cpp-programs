#include "file.h"
#include <conio.h>

int main()
{
	//int arr[7] = {15, 11, 45, 13, 12, 17, 14};
	int arr[7] = { 45, 11, -1, 123, 12, 117, 184 };
	int size = 7;
		
	Heap ob(arr, size);
	ob.makeAHeap();

	ob.heapSort();
	//ob.printElements();

	ob.increaseValueOfNode(-1, 200);
	ob.heapSort();
	ob.printElements();

	_getch();
	return 0;
}