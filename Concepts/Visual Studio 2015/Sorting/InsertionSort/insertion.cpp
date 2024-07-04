#include <iostream>
#include <conio.h>

int main()
{
	int arr[] = { 1000, 101, 500, 700, -20000, 9, 3, 1, -1, 5, 6, 2, 4 };
	int j;
	int key = 0;

	for (int i = 1; i < 13; i++)
	{
		j = i;
		key = arr[i];

		while (key < arr[j - 1] && j > 0)
		{
			arr[j] = arr[j - 1];
			--j;
		}
		arr[j] = key;
	}

	for (int i = 0; i < 13; i++)
	{
		std::cout << arr[i] << " ";
	}

	_getch();
	return 0;
}