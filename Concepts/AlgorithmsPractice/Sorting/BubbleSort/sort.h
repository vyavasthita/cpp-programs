#include <iostream>

class CBubbleSort
{
	public:
		CBubbleSort();
		~CBubbleSort();

		void userConsole();

		void sort();

		void swap(int &first, int& second);

		void printArray();

	private:	
		int* bubbleArray;
		int arraySize;
};