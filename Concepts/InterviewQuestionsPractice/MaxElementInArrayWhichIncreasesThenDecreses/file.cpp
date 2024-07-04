#include <iostream>
#include <conio.h>

using namespace std;

int getMaxElementInArray(int *ptr, int size)
{
	int max = ptr[0];

	for (int i = 1; i < size; i++)
	{
		if (ptr[i] < max)
		{
			return max;
		}
		else
		{
			max = ptr[i];
		}
	}
}


int main()
{
	int size = 24;
	int arr[] = { 1, 3, 5, 7, 9, 11, 13, 15, 18, 20, 48, 55, 54, 53, 52, 43, 32, 21, 10, 8, 6, 4, 2, 0 };
	
	int max = getMaxElementInArray(arr, size);
	cout << max;
	_getch();
}