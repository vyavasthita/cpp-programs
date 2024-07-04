#include <iostream>
#include <conio.h>

using namespace std;

template<class family> void sorting(family arr[], int length)
{
	for(int i = 0; i < length - 1; i++)
	{
		for(int j = 0; j < length - i - 1; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				swapValue(arr[j], arr[j + 1]);
			}
		}
	}
}

template<class family> void swapValue(family &a, family &b)
{
	family temp;
	temp = a;
	a = b;
	b = temp;
}

void main()
{	
	int length = 9;
	int values[] = {9, 5, 8, 3, 1, 2, 6, 4, 7};
	double values2[] = {8.5, 9.7, 87.98, 1.4};
	char values3[] = {'d', 'c', 'a', 'b'};

	sorting(values, length);

	for(int j = 0; j < length; j++)
	{
		cout<<values[j]<<" ";
	}

	length = 4;
	sorting(values2, length);

	cout<<endl;

	for(int j = 0; j < length; j++)
	{
		cout<<values2[j]<<" ";
	}

	sorting(values3, length);

	cout<<endl;

	for(int j = 0; j < length; j++)
	{
		cout<<values3[j]<<" ";
	}

	getch();
}