#include "binary.h"

CBinaryTree::CBinaryTree() : rootNode(NULL), traverseNode(NULL)
{

}

CBinaryTree::~CBinaryTree()
{
	
}

void CBinaryTree::userConsole()
{
	int choice = 0;
	bool bContinue = true;
	int item = 0;

	std::cout << "**********************************************************************\n";
	std::cout << "**********************************************************************\n";
	std::cout << "********************Welcome to Dilip's Binary Tree********************\n\n";

	while(bContinue)
	{
		std::cout << "\n\nPlease select a choice\n\n";

		std::cout << "1. Traverse Binary Tree\n";
		std::cout << "2. Add Node\n";
		std::cout << "3. Delete Node\n";
		std::cout << "4. Search Node\n";
		std::cout << "5. Exit\n\n";

		std::cin >> choice;

		switch(choice)
		{
			case ListChoice::TRAVERSE:
				{
					traverseTree();
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

void CBinaryTree::traverseTree()
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

struct node* CBinaryTree::createNewNode(int item)
{
	struct node* newNode = new struct node;

	newNode->nodeValue = item;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;

	return newNode;
}

void CBinaryTree::addAtFirst(int item)
{
	
}

void CBinaryTree::addAtLast(int item)
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



void CBinaryTree::addNode(int item)
{
	if (rootNode == NULL) //Binary Tree is empty
	{
		traverseNode = createNewNode(item);
		rootNode = traverseNode;
	}
	else	//Binary Tree has some items
	{
		addNodeAt(item);
	}
}

void CBinaryTree::addNodeAt(int item)
{
	while(true)
	{
		if (traverseNode->leftChild == NULL)	//add item at left child
		{
			
		}
		else if(traverseNode->rightChild == NULL)	//add item at right child
		{
		}
		else		//traverse one node deeper
		{
			traverseNode = traverseNode->leftChild;
		}
	}
}

void CBinaryTree::deleteNode(int item)
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

bool CBinaryTree::searchNode(int item)
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