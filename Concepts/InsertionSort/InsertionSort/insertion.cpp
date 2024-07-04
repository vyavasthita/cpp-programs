#include <iostream>
#include <conio.h>

using namespace std;

class Insertion
{
	int num;
	int *items;

	public:
		Insertion()
		{
			num = 0;
		}

		void init();
		void fillItems();
		void swapNum(int*, int, int);
		void insertionSort();
		void print();
};

void Insertion::init()
{
	cout<<"*****Insertion Sort*****\n\n";
	cout<<"Enter The Number of Items :: ";
	cin>>num;

	items = new int[num];
	fillItems();
}

void Insertion::fillItems()
{
	cout<<"\n";
	for(int i = 0; i < num; i++)
	{
		cout<<"Enter "<<(i + 1)<<" Item ::";
		cin>>items[i];
		cout<<endl;
	}
}

void Insertion::insertionSort()
{
	int i, j;
	int start = 0, end = 0;

	for(i = 1; i < num; i++)
	{	  		
		start = end = i;
		for(j = 0; j < i; j++)
		{
			if(items[j] > items[i])
			{
				end = i;
				start = j;
				break;
			}
		}
		swapNum(items, start, end);
	}
}

void Insertion::swapNum(int *ptr, int start, int end)
{
	int temp;
	temp = ptr[end];

	for(int i = end; i > start; i--)
	{
		ptr[i] = ptr[i - 1]; 
	}
	ptr[start] = temp;
}

void Insertion::print()
{
	cout<<"Sorted item(s) are\n";
	for(int i = 0; i < num; i++)
	{
		cout<<"Item "<<(i + 1)<<" --> "<<items[i]<<endl;
	}
}

void main()
{
	Insertion ob;

	ob.init();
	ob.insertionSort();
	ob.print();

	getch();
}