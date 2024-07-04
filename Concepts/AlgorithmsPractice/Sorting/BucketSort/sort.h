#include <iostream>

class CSelectionSort
{
	public:
		CSelectionSort();
		~CSelectionSort();

		void userConsole();

		void sort();

		void swap(int & val1, int & val2);

		int getLargestElement(int* selectionArray, int start, int end);

		void printArray();

	private:	
		int* selectionArray;
		int arraySize;
};