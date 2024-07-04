#include "sort.h"

CInsertionSort::CInsertionSort()
{
}

CInsertionSort::~CInsertionSort()
{
}

void CInsertionSort::userConsole()
{
	std::cout << "**********************************************************************\n";
	std::cout << "**********************************************************************\n";
	std::cout << "********************Welcome to Dilip's Insertion Sort********************\n\n";

	std::cout << "\n\nPlease enter the total no of elements-->";
	std::cin >> arraySize;

	insertionArray = new int[arraySize];

	int item = 0;

	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Please enter the" << " " << i + 1 <<" " << "element-->";
		std::cin >> item;

		insertionArray[i] = item;
	}
}

void CInsertionSort::swap(int *arrayPtr, int rightIndex, int leftIndex)
{
	int temp = 0;

	temp = arrayPtr[rightIndex];

	for (int i = rightIndex; i > leftIndex; i--)
	{
		arrayPtr[i] = arrayPtr[i-1];
	}
	arrayPtr[leftIndex] = temp;
}

void CInsertionSort::sort()
{
	int i, j;

	for (i = 0; i < arraySize; i++)
	{
		for (j = i - 1; j >= 0; j--)
		{	
			if (insertionArray[i] < insertionArray[j])
			{
				continue;
			}
			else
			{
				break;
			}
		}
		swap(insertionArray, i, j);
	}
}

void CInsertionSort::printArray()
{
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Element" << " " << i + 1 <<" " << "is -->";
		std::cout << *insertionArray++ << std::endl;
	}
}