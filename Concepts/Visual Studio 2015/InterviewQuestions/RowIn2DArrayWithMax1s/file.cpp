#include <iostream>
#include <conio.h>

using namespace std;

int getRowIn2DWithMaxNoOf1s(int** arr, int size)
{
	int max = -1;
	int rowIndex = 0;

	for (int i = 0; i < size; i++)
	{
		int count = 0;

		for (int j = 0; j < size; j++)
		{
			if ((arr[i][j] ^ 1) == 0)
			{
				++count;
			}
		}
		if (count > max)
		{
			max = count;
			rowIndex = i;
		}
	}
	return rowIndex;
}


int main()
{
	int size = 3;
	int** input = NULL;

	input = new int*[size];

	for (int i = 0; i < size; i++)
	{
		input[i] = new int[size];
	}

	input[0][0] = 0;
	input[0][1] = 0;
	input[0][2] = 0;

	input[1][0] = 0;
	input[1][1] = 0;
	input[1][2] = 1;

	input[2][0] = 0;
	input[2][1] = 0;
	input[2][2] = 0;

	int res = getRowIn2DWithMaxNoOf1s(input, size);

	cout << res;

	_getch();
}