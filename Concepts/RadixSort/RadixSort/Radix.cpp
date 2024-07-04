#include <iostream>
#include <conio.h>


using namespace std;

class Radix
{
	int iTotalItems;	  //total items
	int iTotalIteration;  //if max num is 234278, means total 6 iterations
	int *iItemsArray;	  
	static int iDivisor;
	int iItemsWithIndex[10][10];   //two D array to hold items on index base, 123 will be stored at index 1, next time index 2, then index 3

	public:
		Radix()
		{
			iTotalItems = 0;
			iTotalIteration = 0;
		} 
		~Radix()
		{
			delete [] iItemsArray;
		}
		void createArray(int row)
		{
			iItemsArray = new int[row];		   			
		}

		void init();
		void calMaxIteration(int);
		void traverseItems();
		void radixSort();
		void colletItemsIndexBasis(int, int, int);
		void mergeItems();
		void clearItems();
		void print();
		
};
int Radix::iDivisor = 1;

void Radix::init()
{
	int iIndex = 0;
	int iValue = 0;

	cout<<"Enter the number of items :: ";
	cin>>iTotalItems;
	createArray(iTotalItems);

	for(iIndex; iIndex < iTotalItems; iIndex++)
	{
		cout<<"Enter Item "<<iIndex + 1<<" : ";
		cin>>iValue;
		iItemsArray[iIndex] = iValue;
		calMaxIteration(iValue);
	} 

	cout<<"\n";
}

void Radix::calMaxIteration(int n)
{
	int length = 0;
	while(n)
	{
		++length;
		n /= 10;
	}

	if(length > iTotalIteration)
	{
		iTotalIteration = length;
	}
} 

void Radix::traverseItems()
{
	while(iTotalIteration)
	{
		radixSort();
		--iTotalIteration;
	}
}
void Radix::radixSort()
{
	int iValue = 0;
	int iRem = 0;
	int columnIndexes[10] = {0};

	for(int iIterator = 0; iIterator < iTotalItems; iIterator++)
	{
		iValue = iItemsArray[iIterator] / iDivisor;
		iRem = iValue % 10;
		colletItemsIndexBasis(columnIndexes[iRem]++, iRem, iItemsArray[iIterator]);
	}
	iDivisor *= 10;
	mergeItems();
}

void Radix::colletItemsIndexBasis(int iColumnIndex, int iRowIndex, int value)
{
	switch(iRowIndex)
	{
		case 0:
			{
				iItemsWithIndex[iRowIndex][iColumnIndex]	= value;
				break;
			}
		case 1:
			{
				iItemsWithIndex[iRowIndex][iColumnIndex]	= value;
				break;
			}
		case 2:
			{
				iItemsWithIndex[iRowIndex][iColumnIndex]	= value;
				break;
			}
		case 3:
			{
				iItemsWithIndex[iRowIndex][iColumnIndex]	= value;
				break;
			}
		case 4:
			{
				iItemsWithIndex[iRowIndex][iColumnIndex]	= value;
				break;
			}
		case 5:
			{
				iItemsWithIndex[iRowIndex][iColumnIndex]	= value;
				break;
			}
		case 6:
			{
				iItemsWithIndex[iRowIndex][iColumnIndex]	= value;
				break;
			}
		case 7:
			{
				iItemsWithIndex[iRowIndex][iColumnIndex]	= value;
				break;
			}
		case 8:
			{
				iItemsWithIndex[iRowIndex][iColumnIndex]	= value;
				break;
			}
		case 9:
			{
				iItemsWithIndex[iRowIndex][iColumnIndex]	= value;
				break;
			}
	}
}

void Radix::mergeItems()
{
	int iIterator = 0;
	for(int iRow = 0; iRow <= iTotalItems; iRow++)
	{
		for(int iColumn = 0; iColumn <= iTotalItems; iColumn++)
		{
			if(iItemsWithIndex[iRow][iColumn] <= 0)
			{
				break;
			}
			iItemsArray[iIterator++] = iItemsWithIndex[iRow][iColumn];
		}
	}
	clearItems();
}

void Radix::clearItems()
{
	for(int iRow = 0; iRow <= iTotalItems; iRow++)
	{
		for(int iColumn = 0; iColumn <= iTotalItems; iColumn++)
		{
			iItemsWithIndex[iRow][iColumn] = NULL;
		}
	}
}
void Radix::print()
{
	cout<<"Sorted items are\n";
	for(int i = 0; i < iTotalItems; i++)
	{
		cout<<iItemsArray[i]<<" ";
	}
}
void main()
{
	Radix ob;

	ob.init();
	ob.traverseItems();
	ob.print();

	getch();  
}