#include <iostream>
#include <conio.h>

void swap(int& a, int& b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

int partition(int arr[], int left, int right)
{
	int pivot = arr[right];

	int partitionIndex = left;

	for (int i = left; i < right - 1; i++)
	{
		if (arr[i] <= pivot)
		{
			swap(arr[i], arr[partitionIndex]);
			partitionIndex = partitionIndex + 1;
		}
	}
	swap(arr[right], arr[partitionIndex]);

	return partitionIndex;
}

void quickSort(int arr[], int left, int right)
{
	int partitionIndex = 0;

	if (left < right)	// not sorted, need to partition it
	{
		partitionIndex = partition(arr, left, right);

		quickSort(arr, left, partitionIndex - 1);
		quickSort(arr, partitionIndex + 1, right);
	}
}

void printItems(int arr[], int left, int right)
{
	for (int i = left; i < right; i++)
	{
		std::cout << arr[i] << " ";
	}
}

// Driver program to test above functions
int main()
{
    int input[] = {1, 7, 8, -1, 0, 9, 5, 10, 12, 17};

	int length = sizeof(input)/sizeof(input[0]);

	quickSort(input, 0, length - 1);

	printItems(input, 0, length - 1);

	getch();
    return 0;
}