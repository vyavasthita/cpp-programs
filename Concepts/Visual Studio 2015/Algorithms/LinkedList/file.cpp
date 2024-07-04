#include "file.h"

using namespace Algorithms;
using namespace std;

LinkedList::LinkedList()
{
	start = NULL;
}

LinkedList::~LinkedList()
{
	struct node* temp = NULL;

	while (start)
	{
		temp = start;
		start = start->next;
		temp->next = NULL;
		delete temp;
		temp = NULL;
	}
}

struct node* LinkedList::CreateNewNode(int value)
{
	struct node* newNode = new node;
	newNode->value = value;
	newNode->next = NULL;

	return newNode;
}

void LinkedList::addNode(int value)
{
	struct node* ptr = NULL;
	struct node* newNode = NULL;

	newNode = CreateNewNode(value);

	if (start == NULL) // List is empty
	{
		start = newNode;
		cout << "\n Value " << value << " added successfully\n";
		return;
	}
	ptr = start;
	
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	ptr->next = newNode;

	cout << "\n Value " << value << " added successfully\n";
}

void LinkedList::deleteNode(int value)
{
	bool bDeleted = false;

	if (start == NULL)
	{
		cout << "\nNo Data available to delete\n";
		return;
	}
	struct node* ptr = start;
	struct node* temp = NULL;

	while (ptr)
	{
		if (ptr->value == value)
		{
			if (ptr == start)	// First node or linked list has only single node
			{
				start = ptr->next;
				ptr->next = NULL;
				delete ptr;
				ptr = NULL;
			}
			else
			{
				temp->next = ptr->next;
				ptr->next = NULL;
				delete ptr;
				ptr = NULL;
			}
			bDeleted = true;
		}
		else
		{
			temp = ptr;
			ptr = ptr->next;
		}
	}
	if (bDeleted == true)
	{
		cout << "\n Value " << value << " deleted successfully\n";
	}
	else
	{
		cout << "\n Value " << value << " not found\n";
	}
}

void LinkedList::reverseList()
{
	if (start == NULL)	// List is empty
	{
		cout << "\n List is empty\n";
		return;
	}
	struct node* prev = NULL;
	struct node* current = NULL;
	struct node* ptr = start;
	struct node* newStart = start;

	while (start->next != NULL)
	{
		while (ptr->next != NULL)
		{
			prev = ptr;
			ptr = ptr->next;
		}

		if (current == NULL)
		{
			ptr->next = newStart;
			newStart = ptr;
			prev->next = NULL;
			current = newStart;			
		}
		else
		{
			ptr->next = current->next;
			current->next = ptr;
			current = ptr;
			prev->next = NULL;
		}
		//start = start->next;
		ptr = start;
	}
	start = newStart;
	cout << "\nList reveresed successfully\n";
	
	/*struct node*  curr_link = start;
	struct node* next_link = NULL;
	struct node* back_link = NULL;

	while (curr_link != NULL)
	{
		start = curr_link;
		next_link = curr_link->next;
		curr_link->next = back_link;
		back_link = curr_link;
		curr_link = next_link;
	}*/
}

void LinkedList::printData()
{
	if (start == NULL)
	{
		cout << "Linked List is empty\n";
		return;
	}

	struct node* ptr = start;

	while (ptr)
	{
		cout << ptr->value << " ";
		ptr = ptr->next;
	}
	cout << "\n\n";
}