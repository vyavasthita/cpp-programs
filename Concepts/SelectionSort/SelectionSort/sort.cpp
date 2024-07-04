#include "sort.h"

CBucketSort::CBucketSort()
{
	
}

CBucketSort::~CBucketSort()
{
}

void CBucketSort::userConsole()
{
	std::cout << "**********************************************************************\n";
	std::cout << "**********************************************************************\n";
	std::cout << "********************Welcome to Dilip's Bucket Sort********************\n\n";

	std::cout << "\n\nPlease enter the total no of elements-->";
	std::cin >> arraySize;

	bucketArray = new int[arraySize];

	int item = 0;

	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Please enter the" << " " << i + 1 <<" " << "element-->";
		std::cin >> item;

		bucketArray[i] = item;
	}

	bucketData = new int*[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		bucketData[i] = new int[arraySize];

		for (int j = 0; j < arraySize; j++)
		{
			bucketData[i][j] = 0;
		}
	}
}

void CBucketSort::swap(int & val1, int & val2)
{
	int temp = 0;

	temp = val1;
	val1 = val2;
	val2 = temp;
}

void CBucketSort::sort()
{
	int i, j, index;

	for (i = 0; i < arraySize; i++)
	{
		createBucket(bucketArray[i]);
	}
}

int CBucketSort::chooseBucket(int item)
{
	int index = 0;

	index = (item/10);

	return index;
}

void CBucketSort::createBucket(int item)
{
	int index = chooseBucket(item);

	fillBucket(item, index);
}

void CBucketSort::fillBucket(int item, int bucketIndex)
{
	for (int i = 0; i < arraySize; i++)
	{
		if (bucketData[bucketIndex][i] != 0)
		{
			continue;
		}
		else
		{
			bucketData[bucketIndex][i] = item;
			break;
		}
	}
}

void CBucketSort::sortBucket()
{
	for (int i = 0; i < arraySize; i++)
	{
	}
}

void CBucketSort::printArray()
{
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Row" << " " << i;

		for (int j = 0; j < arraySize; j++)
		{
			std::cout << "Columen" << " " << j<<" " << "is -->";
			std::cout << bucketData[i][j] << std::endl;
		}
		std::cout << "\n\n";
	}
}