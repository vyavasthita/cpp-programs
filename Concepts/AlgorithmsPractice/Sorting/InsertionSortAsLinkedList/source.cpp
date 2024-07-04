#include <iostream>
#include <conio.h>

struct node
{
	int item;
	struct node* next;
};

class CInsertionSort
{
	public:
		CInsertionSort();
		~CInsertionSort();

		void insertionSort(int newitem);
		void printItems();

	private:
		struct node* ptr;
		struct node* start;
};

CInsertionSort::CInsertionSort()
{
	ptr = start = NULL;
}

CInsertionSort::~CInsertionSort()
{
	struct node* tempNode = NULL;

	while(ptr)
	{
		tempNode = ptr;
		ptr = ptr->next;
		tempNode->next = NULL;
		delete tempNode;
	}
}

void CInsertionSort::insertionSort(int newitem)
{
	struct node* newNode = new struct node;
	newNode->item = newitem;
	newNode->next = NULL;

	if (ptr == NULL)
	{
		ptr = start = newNode;
	}
	else
	{
		if (newitem < ptr->item)
		{
			newNode->next = ptr;
			start = newNode;
		}
		else
		{
			struct node* tempNode = NULL;

			while(ptr && newitem >= ptr->item)
			{
				tempNode = ptr;
				ptr = ptr->next;
			}
			tempNode->next = newNode;
			newNode->next = ptr;
		}
	}
	ptr = start;
}

void CInsertionSort::printItems()
{
	std::cout << "Sorted items are : \n";

	while(ptr)
	{
		std::cout << ptr->item << " ";
		ptr = ptr->next;
	}
	std::cout << std::endl;
	ptr = start;
}

int main()
{
	CInsertionSort oCInsertionSort;

	bool bContinue = true;
	int value = 0;

	while (bContinue)
	{
		std::cout << "Enter 0 to exit\n";
		std::cout << "Enter an item -->";
		std::cin >> value;

		if (value == 0)
		{
			bContinue = false;
		}
		else
		{
			oCInsertionSort.insertionSort(value);
			oCInsertionSort.printItems();
		}
	}
	getch();
	return 1;
}