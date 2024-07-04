#include "LinkedList.h"

CLinkedList::CLinkedList() : ptr(NULL), start(ptr)
{

}

CLinkedList::~CLinkedList()
{
	struct node* tempNode = NULL;

	while(ptr)
	{
		tempNode = ptr->next;
		ptr->next = NULL;
		delete ptr;
		ptr = tempNode;
	}

	if (ptr == NULL)
	{
		std::cout << "Linked List Cleanup is successfull\n";
	}
}

void CLinkedList::userConsole()
{
	int choice = 0;
	bool bContinue = true;
	int item = 0;

	std::cout << "**********************************************************************\n";
	std::cout << "**********************************************************************\n";
	std::cout << "********************Welcome to Dilip's Linked List********************\n\n";

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
					TraverseList();
					break;
				}
			case ListChoice::ADD:
				{
					std::cout << "Enter an node element to add.\n";
					std::cin >> item;

					addNode(item);
					break;
				}
			case ListChoice::DELETE:
				{					
					std::cout << "Enter an node element to delete.\n";
					std::cin >> item;

					deleteNode(item);
					break;
				}
			case ListChoice::SEARCH:
				{
					bool bFound = false;

					std::cout << "Enter an node element to search.\n";
					std::cin >> item;

					bFound = searchNode(item);

					if (bFound)
					{
						std::cout << "Node" << " " << item << " " << "Found\n";
					}
					else
					{
						std::cout << "Node" << " " << item << " " << "not Found\n";
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

void CLinkedList::TraverseList()
{
	if (ptr == NULL)
	{
		std::cout << "List is empty\n";
		return;
	}

	int counter = 1;

	while(ptr)
	{
		std::cout << "Node" << " " << counter++ << " -->";
		std::cout << ptr->data;
		std::cout << "\n";
		ptr = ptr->next;
	}
	ptr = start;
}

struct node* CLinkedList::createNewNode(int item)
{
	struct node* newNode = new struct node;

	newNode->data = item;
	newNode->next = NULL;

	return newNode;
}

void CLinkedList::InitializeList(int item)
{
	ptr = createNewNode(item);

	std::cout << "List initialized with item" << " " << item << std::endl;

	start = ptr;
}

void CLinkedList::addAtFirst(int item)
{
	
}

void CLinkedList::addAtLast(int item)
{
	bool bFound = false;

	bFound = searchNode(item);

	if (bFound)
	{
		std::cout << "Node with item" << " " << item << " " << "already exists." << std::endl;
		return;
	}

	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}

	struct node* nextNode = createNewNode(item);

	ptr->next = nextNode;

	ptr = start;

	std::cout << "New node with item" << " " << item << " " << "added successfully" << std::endl;
}

void CLinkedList::addInBetween(int item)
{
}

void CLinkedList::addNode(int item)
{
	if (start == NULL) //List is empty
	{
		InitializeList(item);
	}
	else
	{
		addAtLast(item);
	}
}

void CLinkedList::deleteNode(int item)
{
	bool bFound = false;
	struct node* temp = NULL;

	if (ptr == NULL)
	{
		std::cout << "List is empty\n";
		return;
	}
	else
	{
		while(ptr)
		{
			if(ptr->data == item)
			{
				bFound = true;
				break;
			}
			else
			{
				temp = ptr;
				ptr = ptr->next;
			}
		}
	}

	if (bFound)	//Item found in the list
	{
		if(start->next == NULL)	//list has only one item
		{
			delete ptr;
			ptr = start = NULL;
		}
		else if(ptr->next == NULL)	//Item is the last item in the list
		{
			delete ptr;
			temp->next = NULL;
		}
		else		//item is somewhere in the list
		{
			temp = ptr->next;
			ptr->next = NULL;
			delete ptr;
			start = temp;
		}
		std::cout << "Node with item" << " " << item << " " << "deleted successfully." << std::endl;
	}
	else		//Item not found in the list
	{
		std::cout << "Node with item" << " " << item << " " << "not found in the list." << std::endl;
	}
	
	ptr = start;
}

bool CLinkedList::searchNode(int item)
{
	bool bFound = false;

	if (ptr == NULL)
	{
		std::cout << "List is empty\n";
		return bFound;
	}

	while(ptr)
	{
		if (ptr->data == item)
		{
			bFound = true;
			break;
		}
		ptr = ptr->next;
	}
	ptr = start;

	return bFound;
}