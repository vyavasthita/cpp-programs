#include <iostream>
#include <conio.h>


class CInsertionSort
{
	public:
		CInsertionSort();
		~CInsertionSort();

		void processItems();
		void insertionSort();
		void moveitems(int* arr, int low, int high);
		void printItems();

	private:
		int *items;
		int size;
};

CInsertionSort::CInsertionSort()
{
	items = new int[size];
}

CInsertionSort::~CInsertionSort()
{
	
}

void CInsertionSort::insertionSort()
{
	int temp = 0;

	for (unsigned int uiIterator = 1; uiIterator < size; uiIterator++)
	{
		for (unsigned int uiIterator2 = 0; uiIterator2 < uiIterator; uiIterator2++)
		{
			if (items[uiIterator] < items[uiIterator2])
			{
				temp = items[uiIterator];
				items[uiIterator2] = items[uiIterator2 - 1];
			}
		}
	}
}

void CInsertionSort::moveitems(int* arr, int low, int high)
{

}

void CInsertionSort::printItems()
{
	std::cout << "Sorted items are : \n";
}

void CInsertionSort::processItems()
{
	std::cout << "Enter the size of array ";
	std::cin >> size;

	for (unsigned int uiIterator = 0; uiIterator < size; uiIterator++)
	{
		std::cout << "Enter item : " << uiIterator + 1;
		std::cin >> items[uiIterator];
	}
}

int main()
{
	CInsertionSort oCInsertionSort;

	oCInsertionSort.processItems();
	oCInsertionSort.insertionSort();
	oCInsertionSort.printItems();

	getch();
	return 1;
}