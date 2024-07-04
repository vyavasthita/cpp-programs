#include "sort.h"

CSelectionSort::CSelectionSort()
{
}

CSelectionSort::~CSelectionSort()
{
}

void CSelectionSort::userConsole()
{
	std::cout << "**********************************************************************\n";
	std::cout << "**********************************************************************\n";
	std::cout << "********************Welcome to Dilip's Selection Sort********************\n\n";

	std::cout << "\n\nPlease enter the total no of elements-->";
	std::cin >> arraySize;

	selectionArray = new int[arraySize];

	int item = 0;

	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Please enter the" << " " << i + 1 <<" " << "element-->";
		std::cin >> item;

		selectionArray[i] = item;
	}
}

void CSelectionSort::swap(int & val1, int & val2)
{
	int temp = 0;

	temp = val1;
	val1 = val2;
	val2 = temp;
}

void CSelectionSort::sort()
{
	int i, j, index;

	for (i = 0; i < arraySize; i++)
	{
		int max = 0;

		for (j = 0; j < arraySize - i; j++)
		{
			if (selectionArray[j] > max)
			{
				max = selectionArray[j];
				index = j;
			}
		}
		swap(selectionArray[index], selectionArray[arraySize - i - 1]);
	}
}

int CSelectionSort::getLargestElement(int* selectionArray, int start, int end)
{
	int i = 0;
	int max = 0;

	for (i = start; i < end; i++)
	{
		if (selectionArray[i] > max)
		{
			max = selectionArray[i];
		}
	}
	return i;
}

void CSelectionSort::printArray()
{
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Element" << " " << i + 1 <<" " << "is -->";
		std::cout << selectionArray[i] << std::endl;
	}
}