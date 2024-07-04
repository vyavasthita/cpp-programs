#include "hashing.h"
#include <conio.h>

using namespace HASH_NM;
using namespace std;

HashTable::HashTable()
{
}

HashTable::~HashTable()
{
	st_Hash *ptr = NULL;
	st_Hash *temp = NULL;

	for (int i = 0; i < m_size; i++)
	{
		ptr = HashArray + i;

		while (ptr)
		{
			temp = ptr;
			ptr = ptr->next;
			temp->next = NULL;
			delete temp;
		}
	}
}

void HashTable::IntitializeHashTable()
{
	int size = 0;

	cout<<"Enter the size of Hash Table->";
	cin>>size;
	m_size = size;

	HashArray = new st_Hash[m_size];

	for (int i = 0; i < m_size; i++)
	{
		HashArray[i].value = 0;
		HashArray[i].next = NULL;
	}
}

int HashTable::GetHash(int value)
{
	int hashValue = value % m_size;
	return hashValue;
}

void HashTable::InsertItem(int item)
{
	st_Hash *temp = NULL;
	int key = GetHash(item);

	start = HashArray + key;

	if (start->next == NULL)
	{
		start->value = item;
	}
	else
	{
		st_Hash *newitem = new st_Hash;
		newitem->value = item;
		newitem->next = NULL;

		temp = start;
		
		while (temp->next != NULL)
		{			
			temp = temp->next;
		}
		temp = newitem;
	}
}

void HashTable::PrintItem()
{
	for (int i = 0; i < m_size; i++)
	{
		start = HashArray + i;
		cout<<"Values at key "<<i<<" are->";
		while (start)
		{
			if (start->value != 0)
			{
				cout<<start->value<<" ";
			}
			start = start->next;
		}
		cout<<"\n";
	}
}

void HashTable::DeleteItem(int item)
{
}

int HashTable::CountItems()
{
	return 1;
}

void main()
{
	int choice = 0;
	int item = 0;
	bool bExit = true;

	HashTable ob;
	ob.IntitializeHashTable();

	while (bExit)
	{
		cout<<"\nSelect a Choice\n";
		cout<<"1. Insert Item\n";
		cout<<"2. Delete Item\n";
		cout<<"3. Print Items\n";
		cout<<"4. Hash Size\n";
		cout<<"5. Exit\n";

		cin>>choice;

		switch(choice)
		{
			case INSERT:
			{
				cout<<"Enter an item to insert\n";
				cin>>item;

				ob.InsertItem(item);
				break;
			}

			case DELETE:
			{
				cout<<"Enter an item to delete\n";
				cin>>item;

				ob.DeleteItem(item);
				break;
			}

			case PRINT:
			{
				cout<<"Items are\n";
				ob.PrintItem();
				break;
			}

			case COUNT:
			{
				cout<<"Hash contains "<<ob.CountItems()<<" "<<"Items\n";
				break;
			}

			case EXIT:
			{
				bExit = false;
				break;
			}
			default:
			{
				cout<<"Wrong Input\n";
				break;
			}
		}
	}
	getch();
}