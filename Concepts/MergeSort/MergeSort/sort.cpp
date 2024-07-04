#include "sort.h"


CMergeSort::CMergeSort()
{
}

CMergeSort::~CMergeSort()
{
}

void CMergeSort::userConsole()
{
	std::cout << "**********************************************************************\n";
	std::cout << "**********************************************************************\n";
	std::cout << "********************Welcome to Dilip's Merge Sort********************\n\n";

	std::cout << "\n\nPlease enter the total no of elements-->";
	std::cin >> arraySize;

	mergeArray = new int[arraySize];

	int item = 0;

	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Please enter the" << " " << i + 1 <<" " << "element-->";
		std::cin >> item;

		mergeArray[i] = item;
	}
}

void CMergeSort::divideItems(int items[], int length)
{
	if (length == 1)
	{
		return;
	}

	const int sizeOfLeftItems = length/2;
	const int sizeOfRightItems = length/2; 	

	int leftItems[sizeOfLeftItems];
}

void CMergeSort::mergeSort()
{
	int index = 0;

	for (int i = 0; i < itemLength; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			index = getIndex(mergeArray[j]);
			digitArray[index] = mergeArray[j];
		}
		digitIndexDivisor *= 10;
		refillRadixArray();
	}
}

void CMergeSort::refillRadixArray()
{
	for (int i = 0; i < arraySize; i++)
	{
		mergeArray[i] = digitArray[i];
	}
}

void CMergeSort::printArray()
{
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Element " << i + 1 << " --> ";
		std::cout << mergeArray[i] << "\n";
	}
}