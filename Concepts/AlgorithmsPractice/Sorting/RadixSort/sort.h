#include <iostream>

class CRadixSort
{
	public:
		CRadixSort();
		~CRadixSort();

		void userConsole();

		int getIndex(int item);

		void radixSort();

		int getMax();

		int getLength();

		void refillRadixArray();

		void printArray();

	private:	
		int* radixArray;
		int* digitArray;
		int arraySize;

		int itemLength;

		static short int digitIndexCount;
		int digitIndexDivisor;
};