#include "file.h"
#include <limits>
#include <conio.h>

Merging::Merging()
{

}

Merging::~Merging()
{
}

void Merging::divide(int* input, int start, int end)
{
	int mid = 0;
	if (start < end)
	{
		mid = (end + start) / 2;

		divide(input, start, mid);
		divide(input, mid + 1, end);
		conquer(input, start, mid, end);
	}
}

void Merging::conquer(int* input, int start, int mid, int end)
{
	int leftSize = (mid - start) + 1;
	int rightSize = end - mid;

	std::cout << "left size " << leftSize << std::endl;
	std::cout << "right size " << rightSize << std::endl;

	leftInput = new int[leftSize + 1];
	rightInput = new int[rightSize + 1];

	int i, j, k;

	for (i = 0; i < leftSize; i++)
	{
		leftInput[i] = input[i];
	}
	leftInput[i] = std::numeric_limits<int>::max();

	for (j = 0; j < rightSize; j++)
	{
		rightInput[j] = input[i++];
	}

	rightInput[j] = std::numeric_limits<int>::max();

	for (k = 0, i = 0, j = 0; i < leftSize || j < rightSize; k++)
	{
		if (leftInput[i] <= rightInput[j])
		{
			input[k] = leftInput[i++];
		}
		else
		{			
			input[k] = rightInput[j++];
		}
	}
}

void Merging::printInput(int input[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << input[i] << " ";
	}
}

int main()
{
	Merging merging;

	int arr[8] = {9, 3, 1, -1, 5, 6, 2, 4};
	//int arr[2] = { 7, 5};
	merging.divide(arr, 0, 7);
	merging.printInput(arr, 8);
	_getch();

	return 0;
}


