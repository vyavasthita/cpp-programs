#include "file.h"
#include <iostream>
#include <vector>

using namespace LINKEDLIST;

LinkedList::LinkedList() :
	m_rootFirst(NULL), m_rootSecond(NULL)
{
	
}

LinkedList::~LinkedList()
{
	NODE* temp = NULL;

	while (m_rootFirst)
	{
		temp = m_rootFirst;
		m_rootFirst = m_rootFirst->next;
		temp->next = NULL;
		delete temp;
		temp = NULL;
	}

	while (m_rootSecond)
	{
		temp = m_rootSecond;
		m_rootSecond = m_rootSecond->next;
		temp->next = NULL;
		delete temp;
		temp = NULL;
	}
}

NODE* LinkedList::createNewNode(int value)
{
	NODE* newNode = new NODE;

	newNode->value = value;
	newNode->next = NULL;

	return newNode;
}

void LinkedList::createLinkedListFromArray(int* item, int length)
{
	NODE* ptr = m_rootFirst;
	NODE* newNode = NULL;

	for (int i = 0; i < length; i++)
	{
		newNode = createNewNode(item[i]);

		if (ptr == NULL)
		{
			ptr = newNode;
			m_rootFirst = ptr;
		}
		else
		{
			ptr->next = newNode;
			ptr = ptr->next;
		}
	}
}

void LinkedList::processList(NODE* ptr)
{
	static NODE* ptr1 = m_rootFirst;
    static NODE* ptr2 = m_rootSecond;

	static int carry = 0;

	if (ptr1)
	{
		processList(ptr1->next);
	}

	if (ptr2)
	{
		processList(ptr2->next);
	}

	if (ptr1 != NULL || ptr2 != NULL)
	{
		int res = ptr->value + ptr2->value + carry;

		if (res > 9)
		{
			carry = res - 9;
		}
		std::cout << res << std::endl;
	}
}