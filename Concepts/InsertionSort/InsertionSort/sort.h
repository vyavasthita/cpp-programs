#include <iostream>

class CInsertionSort
{
	public:
		CInsertionSort();
		~CInsertionSort();

		void userConsole();

		void sort();

		void swap(int *arrayPtr, int rightIndex, int leftIndex);

		void printArray();

	private:	
		int* insertionArray;
		int arraySize;
};