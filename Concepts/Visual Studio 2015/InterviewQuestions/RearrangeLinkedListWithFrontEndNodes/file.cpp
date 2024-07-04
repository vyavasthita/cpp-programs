#include "file.h"


using namespace LINKEDLIST;
using namespace std;


LinkedList::~LinkedList()
{
	NODE* temp = head;

	while (head)
	{
		head = head->next;
		temp->next = NULL;
		delete temp;
		temp = head;
	}
}

NODE* LinkedList::createNewNode(int value)
{
	NODE* newNode = new NODE;

	newNode->value = value;
	newNode->next = NULL;

	return newNode;
}

LinkedList::LinkedList(int size) : head(NULL), m_nSize(size)
{
	NODE* ptr = NULL;

	for (int i = 0; i < m_nSize; i++)
	{
		NODE* newNode = createNewNode(i + 1);

		if (head == NULL)
		{
			head = newNode;
			ptr = head;
		}
		else
		{
			ptr->next = newNode;
			ptr = ptr->next;
		}
	}
}

void LinkedList::rearrangeNodes()
{
	NODE* currentStart = head;
	NODE* start = head;
	NODE* ptr = head;
	NODE* prev = NULL;
	NODE* current = NULL;

	while (currentStart->next->next)
	{
		while (ptr->next)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = NULL;
		currentStart = currentStart->next;
		start->next = ptr;

		if (current != NULL)
		{
			current->next = start;
		}
		current = ptr;
		start = currentStart;
		ptr = currentStart;
	}
	current->next = currentStart;
}

void LinkedList::print()
{
	NODE* ptr = head;

	while (ptr)
	{
		cout << ptr->value << " ";
		ptr = ptr->next;
	}
}