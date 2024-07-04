#include <iostream>
#include <conio.h>

using namespace std;

class Merge
{
	int num;
	int *items;

	public:
		Merge()
		{
			num = 0;
		}
		void init();
		void mergeSort(int *, int, int);
		void sortItems(int *, int, int);
		void print();
};

void Merge::init()
{
	cout<<"Enter the number of items :: ";
	cin>>num;

	items = new int[num];

	for(int i = 0; i < num; i++)
	{
		cout<<"Enter " << (i + 1) << " item ::";
		cin>>items[i];
		cout<<endl;
	}
	mergeSort(items, 0, num);
}

void Merge::mergeSort(int *ptr, int start, int end)
{
	int mid;
	mid = end/2;
	if(start = mid - 1)
	{
		mergeSort(ptr, start, mid);
		mergeSort(ptr, mid + 1, end);
	}
	cout<<"Hi\n";
}

void Merge::sortItems(int *p, int start, int end)
{
	cout<<"Hi\n";
}

void Merge::print()
{
	cout<<"Sorted items are\n";
	for(int i = 0; i < num; i++)
	{
		cout<<items[i]<<endl;
	}
}
void main()
{
	Merge ob;

	ob.init();
	//ob.print();

	getch();
}