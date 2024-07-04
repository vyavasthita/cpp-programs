//An example:
// 
//If we are going to sort the following range of numbers: 
//3, 2, 5, 1, 4 
//
//We will start by comparing 3 to every number in the range, and swap it for the lowest one. 
//In this, the first loop, we will swap 3 with 1, which is currently the lowest number in the range. The numbers will now look like this:
// 1, 2, 5, 3, 4 
//
//We then continue by checking 2, the second element, with the rest of the elements. 
//There is, however, no value after 2 that is lower than it, so it will have to stay put. The range still looks like this:
// 1, 2, 5, 3, 4 
//
//So we check the third element in the range, 5. It turns out that 3 is the lowest value within the range of numbers left, 
//so we swap 5 and 3. The numbers will now look like this:
// 1, 2, 3, 5, 4 
//
//And so we make a fourth check, and as 4 is the lowest number, and is lower than 5, we swap them and end up with this:
// 1, 2, 3, 4, 5 
//
//We can make no more checks since there are no numbers left, but as we can see, the range of numbers is now perfectly sorted, 
//and we have sorted it in very logical manners.


#include <iostream>
#include <conio.h>

using namespace std;

class Selection
{
	int num;
	int *items;
	public:
		Selection()
		{
			num = 0;
		}
		void init();
		void fillItems();
		void swapNum(int&, int&);
		void selectionSort();
		void print();
};

void Selection::init()
{
	cout<<"how many items you want to enter :: \n";
	cin>>num;

	items = new int[num];
	fillItems();
}

void Selection::fillItems()
{
	for(int i = 0; i < num; i++)
	{
		cout<<"Enter "<<(i + 1)<<" item ::";
		cin>>items[i];
		cout<<endl;
	}
}

void Selection::selectionSort()
{
	int lowest = 0;
	int pos = 0;

	for(int i = 0; i < num - 1; i++)
	{
		lowest = items[i];
		pos = i;
		for(int j = i; j < num - 1; j++)
		{
			if(items[j + 1] < lowest)
			{
				pos = j + 1;
				lowest = items[j + 1];
			}
		}
		swapNum(items[i], items[pos]);
	}
}

void Selection::swapNum(int &a, int &b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

void Selection::print()
{
	cout<<"Sorted items are\n";
	for(int i = 0; i < num; i++)
	{
		cout<<items[i]<<endl;
	}
}

void main()
{
	Selection ob;
	ob.init();
	ob.selectionSort();
	ob.print();
	getch();
}