#include <iostream>

class CMergeSort
{
	public:
		CMergeSort();
		~CMergeSort();

		void userConsole();

		void divideItems(int items[], int length);

		void conquerItems(int items[], int length);

		void mergeSort();

		void refillRadixArray();

		void printArray();

	private:	
		int* mergeArray;
		int arraySize;
};