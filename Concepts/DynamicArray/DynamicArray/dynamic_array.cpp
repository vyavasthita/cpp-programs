#include "dynamic_array.h"

using namespace std;

int DArray::siCurrArrIndex = 0;

DArray::DArray()
{
}

DArray::DArray(int size)
{
	miSize = size;
	dynamicArray = new int(size);

	for(int iIterator = 0; iIterator < miSize; ++iIterator)
	{
		dynamicArray[iIterator] = 0;
	}
}

DArray::~DArray()
{
}

void DArray::init()
{
	unsigned short usChoice = 0;
	bool bIsExit = false;
	int iItem = 0;
	bool bIsFound = false;

	clearScreen();

	while(!bIsExit)
	{
		cout<<"*****Dynamic Array****\n\n";
		cout<<"1. Insert\n";
		cout<<"2. Delete\n";
		cout<<"3. Search\n";
		cout<<"4. Print\n";
		cout<<"5. Count\n";
		cout<<"6. Exit\n";

		cin>>usChoice;
		clearScreen();

		switch(usChoice)
		{
			case INSERT:
			{
				cout<<"Enter an Item to insert\n";
				cin>>iItem;
				pushBack(iItem);

				break;
			}
			case DELETE:
			{
				cout<<"Enter an Item to delete\n";
				cin>>iItem;
				deleteItem(iItem);

				break;
			}
			case SEARCH:
			{
				cout<<"Enter an Item to search\n";
				cin>>iItem;
				bIsFound = search(iItem);

				if(bIsFound)
				{
					cout<<"Item Found\n";
				}
				else
				{
					cout<<"Item Not Found\n";
				}

				break;
			}
			case PRINT:
			{
				print();
				break;
			}
			case COUNT:
			{
				cout<<"No of items are : "<<size()<<endl;
				break;
			}
			case EXIT:
			{
				bIsExit = true;
				break;
			}
		}
	}
}

void DArray::pushBack(int item)
{
	if(siCurrArrIndex == size())
	{
		resizeArray(1);
	}
	dynamicArray[siCurrArrIndex++] = item;
	
	cout<<"Item Inserted Successfully\n";
}

void DArray::deleteItem(int item)
{
	bool bIsFound = false;

	clearScreen();

	bIsFound = search(item);

	if(bIsFound)
	{
		for(int iLB = iSearchItemIndex; iLB < size(); ++iLB)
		{
			dynamicArray[iLB] = dynamicArray[iLB + 1]; 
		}
		resizeArray(-1);
		
		cout<<"Item Deleted Successfully\n";
	}
	else
	{
		cout<<"Item Not Found\n";
	}
}

void DArray::resizeArray(short int sizeVar)
{
	int *newArray = new int[size() + sizeVar];
	
	for(int iIterator = 0; iIterator < size(); ++iIterator)
	{
		newArray[iIterator] = dynamicArray[iIterator];
	}
	delete [] dynamicArray;
	dynamicArray = newArray;
	miSize += sizeVar;
}

bool DArray::search(int item)
{
	iSearchItemIndex = 0;
	bool bIsItemFound = false;

	for(int iIterator = 0; iIterator < size(); ++iIterator)
	{
		iSearchItemIndex++;

		if(item == dynamicArray[iIterator])
		{
			bIsItemFound = true;
			break;
		}
	}
	return (bIsItemFound);
}

void DArray::print()
{
	clearScreen();
	
	cout<<"Items are : \n";

	for(int iIterator = 0; iIterator < size(); ++iIterator)
	{
		cout<<dynamicArray[iIterator]<<" ";
	}
	cout<<endl;
}

int DArray::size()
{
	return (miSize);
}

void DArray::clearScreen()
{
	system("cls");
}

void main()
{
	int size = 0;

	cout<<"Enter the initial size of the array\n";
	cin>>size;

	DArray* dArray = new DArray(size);
	dArray->init();
	delete dArray;
}

