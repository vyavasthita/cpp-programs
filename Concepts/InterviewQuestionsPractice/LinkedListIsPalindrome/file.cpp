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

LinkedList::LinkedList() : 
	head(NULL), prev(NULL)
{
	
}

void LinkedList::addNode(int item)
{
	NODE* ptr = head;

	NODE* newNode = createNewNode(item);

	if (ptr == NULL)
	{
		head = newNode;
		return;
	}

	while (ptr->next)
	{
		ptr = ptr->next;
	}
	ptr->next = newNode;
}

bool LinkedList::isPalindrome()
{
	NODE* ptr = head;

	while (ptr)
	{
		if (m_vecItems.size() == 0 || (m_vecItems.size() == 1 && ptr->value != m_vecItems[0]))
		{
			m_vecItems.push_back(ptr->value);
		}
		else //Vecor size is already 2
		{
			if (ptr->value == m_vecItems.back())
			{
				m_vecItems.pop_back();
			}
			else if (ptr->value == m_vecItems.at(m_vecItems[m_vecItems.size() - 2]))
			{
				{
					m_vecItems.erase(m_vecItems.end() - 3);
				}
			}
			else
			{
				return false;
			}
		}
		ptr = ptr->next;
	}
	if (m_vecItems.size() == 0 || m_vecItems.size() == 1)
	{
		return true;
	}

	return false;
}

void LinkedList::traverseList()
{
	NODE* ptr = head;

	printInReverseOrder(ptr);
}

void LinkedList::printInReverseOrder(NODE* ptr)
{
	if (ptr)
	{
		printInReverseOrder(ptr->next);
	}

	if (ptr != NULL)
	{
		cout << ptr->value << endl;
	}
}

void LinkedList::print()
{
	NODE* ptr = head;

	while (ptr)
	{
		cout << ptr->value << endl;
		ptr = ptr->next;
	}
}