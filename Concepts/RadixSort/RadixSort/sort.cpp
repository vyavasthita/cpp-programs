#include "sort.h"

short int CRadixSort::digitIndexCount = 0;

CRadixSort::CRadixSort()
{
}

CRadixSort::~CRadixSort()
{
}

void CRadixSort::userConsole()
{
	std::cout << "**********************************************************************\n";
	std::cout << "**********************************************************************\n";
	std::cout << "********************Welcome to Dilip's Bucket Sort********************\n\n";

	std::cout << "\n\nPlease enter the total no of elements-->";
	std::cin >> arraySize;

	radixArray = new int[arraySize];

	int item = 0;

	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Please enter the" << " " << i + 1 <<" " << "element-->";
		std::cin >> item;

		radixArray[i] = item;
	}

	digitArray = new int[arraySize];

	itemLength = getLength();
}

int CRadixSort::getMax()
{
	int max = 0;

	for (int i = 0; i < arraySize; i++)
	{
		if (radixArray[i] > max)
		{
			max = radixArray[i];
		}
	}
	return max;
}

int CRadixSort::getLength()
{
	int length = 0;

	int res = getMax();

	while(res)
	{
		res /= 10;
		++length;
	}

	return length;
}

int CRadixSort::getIndex(int item)
{
	int index = 0;
	int result = 0;

	result = item / digitIndexDivisor;

	result = result % 10;

	//digitIndexDivisor *= 10;

	return index;
}

void CRadixSort::radixSort()
{
	int index = 0;

	for (int i = 0; i < itemLength; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			index = getIndex(radixArray[j]);
			digitArray[index] = radixArray[j];
		}
		digitIndexDivisor *= 10;
		refillRadixArray();
	}
}

void CRadixSort::refillRadixArray()
{
	for (int i = 0; i < arraySize; i++)
	{
		radixArray[i] = digitArray[i];
	}
}

void CRadixSort::printArray()
{
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Element " << i + 1 << " --> ";
		std::cout << radixArray[i] << "\n";
	}
}