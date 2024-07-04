#include "file.h"

MyArray::MyArray()
{
	
}

void MyArray::reverseArray(int* input, int size, int chunk)
{
	int rem = size;
	int start = 0;
	int end = 0;

	int loop = size / chunk;

	while (loop--)
	{
		if (rem >= chunk)
		{
			end = start + chunk - 1;
			rem -= chunk;
		}
		else
		{
			end = size - rem + 1;
		}
		
		reverseArrayInChunks(input, start, end);

		start += chunk;
		
		size /= chunk;
	}
}

void MyArray::reverseArrayInChunks(int* input, int start, int end)
{
	while (end > start)
	{
		swapNum(&input[start], &input[end]);
		--end;
		++start;
	}
}

void MyArray::swapNum(int * first, int* second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

void MyArray::printArray(int* input, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << input[i] << "  ";
	}
}