#include "file.h"
#include <limits>
#include <conio.h>

using namespace std;


Quick::Quick()
{

}

Quick::~Quick()
{
}

void Quick::quickSort(int* input, int start, int end)
{
	int loc = 0;

	if (start < end)
	{
		loc = partition(input, start, end);

		quickSort(input, start, loc - 1);
		quickSort(input, loc + 1, end);		
	}
}

void Quick::swapNum(int& first, int& second)
{
	cout << first << " " << second;
	int temp = first;
	first = second;
	second = temp;
}

int Quick::partition(int* input, int start, int end)
{
	int i = -1;
	int j = 0;
	int pivot = input[end];

	for (j; j < end; j++)
	{
		if (input[j] <= pivot)
		{
			++i;
			swapNum(input[j], input[i]);
		}
	}
	swapNum(input[j + 1], input[end]);
	return i + 1;
}

void Quick::printInput(int input[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << input[i] << " ";
	}
}

int main()
{
	Quick q;

	int arr[8] = { 9, 3, 1, -1, 5, 6, 2, 4 };
	//int arr[2] = { 7, 5};
	q.quickSort(arr, 0, 7);
	q.printInput(arr, 8);
	_getch();

	return 0;
}


