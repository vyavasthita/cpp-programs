#include "file.h"
#include <conio.h>


int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

	MyArray ob;

	ob.reverseArray(arr, 9, 3);
	ob.printArray(arr, 9);

	_getch();
	
	return 0;
}