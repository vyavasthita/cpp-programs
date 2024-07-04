#include <iostream>
#include <conio.h>

struct node
{
	int item;
	struct node* next;
};

class CSelectionSort
{
	public:
		CSelectionSort();
		~CSelectionSort();

		void selectionSort();
		void insertItem(int item);
		void processItems();
		void printItems();

	private:
		struct node* ptr;
		struct node* start;
		int size;
		int* items;
};

CSelectionSort::CSelectionSort()
{
	ptr = start = NULL;
	items = new int[size];
}

CSelectionSort::~CSelectionSort()
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

void CSelectionSort::insertItem(int item)
{
	struct node* newNode = new struct node;
	newNode->item = item;
	newNode->next = NULL;

	if (ptr == NULL)
	{
		ptr = start = newNode;
	}
	else
	{
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = newNode;
	}
	ptr = start;
}

void CSelectionSort::selectionSort()
{
	int max = 0;

	while (ptr)
	{
		if (ptr->item > max)
		{
			max = ptr->item;
		}
		ptr = ptr->next;
	}
}

void CSelectionSort::printItems()
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

void CSelectionSort::processItems()
{
	
}

int main()
{
	CSelectionSort oCSelectionSort;

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
			oCSelectionSort.insertItem(value);
			oCSelectionSort.selectionSort();
			oCSelectionSort.printItems();
		}
	}

	getch();
	return 1;
}