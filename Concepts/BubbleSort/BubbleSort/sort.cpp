#include "sort.h"

CBubbleSort::CBubbleSort()
{
}

CBubbleSort::~CBubbleSort()
{
}

void CBubbleSort::userConsole()
{
	std::cout << "**********************************************************************\n";
	std::cout << "**********************************************************************\n";
	std::cout << "********************Welcome to Dilip's Bubble Sort********************\n\n";

	std::cout << "\n\nPlease enter the total no of elements-->";
	std::cin >> arraySize;

	bubbleArray = new int[arraySize];

	int item = 0;

	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Please enter the" << " " << i + 1 <<" " << "element-->";
		std::cin >> item;

		bubbleArray[i] = item;
	}
}

void CBubbleSort::swap(int &first, int& second)
{
	int temp = 0;

	temp = first;
	first = second;
	second = temp;
}

void CBubbleSort::sort()
{
	for (int i = 0; i < arraySize - 1; i++)
	{
		for (int j = 0; j < arraySize - i - 1
			; j++)
		{
			if (bubbleArray[j] > bubbleArray[j + 1])
			{
				swap(bubbleArray[j], bubbleArray[j + 1]);
			}
		}
	}
}

void CBubbleSort::printArray()
{
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Element" << " " << i + 1 <<" " << "is -->";
		std::cout << bubbleArray[i] << std::endl;
	}
}