#include <iostream>
#include <conio.h>

using namespace std;

class Bubble
{
	int num;
	int *items;
	public:
		Bubble()
		{
			num = 0;
		}
		void init();
		void fillItems();
		void swapNum(int&, int&);
		void bubbleSort();
		void print();
};

void Bubble::init()
{
	cout<<"how many items you want to enter :: \n";
	cin>>num;

	items = new int[num];
	fillItems();
}

void Bubble::fillItems()
{
	for(int i = 0; i < num; i++)
	{
		cout<<"Enter "<<(i + 1)<<" item ::";
		cin>>items[i];
		cout<<endl;
	}
}

void Bubble::bubbleSort()
{
	for(int i = 0; i < num - 1; i++)
	{
		for(int j = 0; j < num - i - 1; j++)
		{
			if(items[j] > items[j + 1])
			{
				swapNum(items[j], items[j + 1]);
			}
		}
	}
}

void Bubble::swapNum(int &a, int &b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

void Bubble::print()
{
	cout<<"Sorted items are\n";
	for(int i = 0; i < num; i++)
	{
		cout<<items[i]<<endl;
	}
}
void main()
{
	Bubble ob;
	ob.init();
	ob.bubbleSort();
	ob.print();
	getch();
}