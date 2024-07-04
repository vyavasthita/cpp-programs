#include "hash.h"

int CHashMap::hashMapSize = 23;

CHashMap::CHashMap() : ptr(NULL)
{
	hashMapArray = new struct node[hashMapSize];

	for (int i = 0; i < hashMapSize; i++)
	{
		hashMapArray[i].next = NULL;
	}
}

CHashMap::~CHashMap()
{
	for (int i = 0; i < hashMapSize; i++)
	{
		struct node* tempNode = NULL;

		ptr = hashMapArray[i].next;

		while(ptr)
		{
			tempNode = ptr->next;
			ptr->next = NULL;
			delete ptr;
			ptr = tempNode;
		}
	}
}

void CHashMap::userConsole()
{
	int choice = 0;
	bool bContinue = true;
	int item = 0;

	std::cout << "**********************************************************************\n";
	std::cout << "**********************************************************************\n";
	std::cout << "********************Welcome to Dilip's Hash Table*********************\n\n";

	while(bContinue)
	{
		std::cout << "\n\nPlease select a choice\n\n";

		std::cout << "1. Traverse List\n";
		std::cout << "2. Add Node\n";
		std::cout << "3. Delete Node\n";
		std::cout << "4. Search Node\n";
		std::cout << "5. Exit\n\n";

		std::cin >> choice;

		switch(choice)
		{
			case ListChoice::TRAVERSE:
				{					
					break;
				}
			case ListChoice::ADD:
				{
					std::cout << "Enter an item to add.\n";
					std::cin >> item;

					addItem(item);
					break;
				}
			case ListChoice::DELETE:
				{			
					
				}
			case ListChoice::SEARCH:
				{
					bool bFound = false;

					std::cout << "Enter an node element to search.\n";
					std::cin >> item;

					bFound = searchItem(item);

					if (bFound)
					{
						std::cout << "Item" << " " << item << " " << "Found\n";
					}
					else
					{
						std::cout << "Item" << " " << item << " " << "not Found\n";
					}

					break;
				}
			case ListChoice::EXIT:
				{
					bContinue = false;
					break;
				}
			default:
				{
					std::cout << "Invalid Input\n\n";
				}
		}
	}
}

struct node* CHashMap::createNewNode(int item)
{
	struct node* newNode = new struct node;

	newNode->data = item;
	newNode->next = NULL;

	return newNode;
}

void CHashMap::InitializeHashMap(int item)
{
	
}

void CHashMap::addItem(int item)
{
	struct node* newNode = createNewNode(item);

	int key = hashFunction(item);

	ptr = hashMapArray[key].next;

	if (hashMapArray[key].next == NULL)	//no item present at the given array index
	{
		hashMapArray[key].next = newNode;
	}
	else		//Index already has an item, traverse thru linked list to add the item
	{
		while(hashMapArray[key].next != NULL)
		{
			ptr = ptr->next;
		}
		ptr = newNode;
	}

	std::cout << "Item" << " " << item << " " << "added successfully" << std::endl;
}

bool CHashMap::searchItem(int item)
{
	bool bFound = false;

	int key = hashFunction(item);

	ptr = hashMapArray[key].next;

	while(ptr)
	{
		if (ptr->data == item)
		{
			bFound = true;
			break;
		}
		else
		{
			ptr = ptr->next;
		}
	}
	return bFound;
}

int CHashMap::hashFunction(int item)
{
	int key = item % hashMapSize;

	return key;

}