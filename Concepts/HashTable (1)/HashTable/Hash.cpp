#include "Hash.h"
#include <conio.h>
#include <assert.h>

using namespace NSHashTable;
using namespace std;

MyHashTable::MyHashTable()
{
	ptr = NULL;
};

MyHashTable::MyHashTable(long int size)
{
	ptr = NULL;
	mi_Size = size;
	arrRecord = new struct st_Record[size];

	for(int iIterator = 0; iIterator < mi_Size; ++iIterator)
	{
		arrRecord[iIterator].value = 0;
		arrRecord[iIterator].next = NULL;
	}
};

MyHashTable::~MyHashTable()
{
	struct st_Record* ptrRecord;
	struct st_Record* ptrTraverseList;
	struct st_Record* temp;

	for(int iIterator = 0; iIterator < mi_Size; ++iIterator)
	{
		ptrRecord = arrRecord + iIterator;		//to hold array Index's pointer

		if(ptrRecord->next != NULL)		//Multiple entries for same key, so first delete those entries
		{
			ptrTraverseList = ptrRecord->next;		// to hold address of first node attached to same array index
		
			ptrRecord->next = NULL;		//make address of array to NULL
			temp = ptrTraverseList;

			while(ptrTraverseList)
			{
				temp = ptrTraverseList->next;
				ptrTraverseList->next = NULL;
				delete ptrTraverseList;
				ptrTraverseList = temp;
			}
		}		
	}
	delete [] arrRecord;
}

int MyHashTable::hash(long int& number)
{
	int key = 0;
	key = number % mi_Size;
	return (key);
}

void MyHashTable::insertRecord(long int& record)
{
	long int key = hash(record);
	ptr = arrRecord + key;

	if(ptr->value == 0)
	{
		ptr->value = record;
	}
	else 
	{
		struct st_Record* newRecord = new struct st_Record;
		newRecord->value = record;
		newRecord->next = NULL;

		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = newRecord;
	}
	cout<<"Record Inserted Successfully\n";
}

bool MyHashTable::searchRecord(long int& record)
{
	bool bRecordFound = false;
	long int key = hash(record);
	ptr = arrRecord + key;

	while(ptr)
	{
		if(ptr->value == record)
		{
			bRecordFound = true;
			break;
		}
		ptr = ptr->next;
	}
	
	return (bRecordFound);
}

bool MyHashTable::deleteRecord(long int& record)
{
	bool bIsDeleted = false;
	struct st_Record* temp = NULL;
	long int key = hash(record);
	ptr = arrRecord + key;

	if(ptr->next == NULL)	//at array index
	{
		if(ptr->value == record)
		{
			ptr->value = 0;
			bIsDeleted = true;
		}
	}
	else
	{
		while(ptr)
		{
			temp = ptr;
			ptr = ptr->next;
			
			if(ptr->value == record)
			{
				if(ptr->next == NULL)
				{
					temp->next = NULL;					
				}
				else
				{
					temp->next = ptr->next;
					ptr->next = NULL;					
				}
				delete ptr;
				bIsDeleted = true;
				break;
			}
		}
	}

	return (bIsDeleted);
}

void MyHashTable::init()
{
	unsigned short usChoice = 0;
	bool bIsExit = false;
	long int lRecord = 0;
	bool bIsRecordFound = false;

	while(!bIsExit)
	{
		cout<<"*****Hash Table*****\n\n";
		cout<<"1. Insert a Record\n";
		cout<<"2. Search a Record\n";
		cout<<"3. Delete a Record\n";
		cout<<"4. Exit\n";

		cin>>usChoice;

		switch(usChoice)
		{
			case INSERT:
			{
				cout<<"Enter A Record to insert\n";
				cin>>lRecord;

				insertRecord(lRecord);
				break;
			}
			case SEARCH:
			{
				cout<<"Enter A Record to search\n";
				cin>>lRecord;

				bIsRecordFound = searchRecord(lRecord);
				if(bIsRecordFound)
				{
					cout<<"Record Found\n";
				}
				else
				{
					cout<<"Record Doesn't Exit\n";
				}

				break;
			}
			case DELETE:
			{
				cout<<"Enter A Record to delete\n";
				cin>>lRecord;

				bIsRecordFound = deleteRecord(lRecord);
					
				if(bIsRecordFound)
				{
					cout<<"Record Deleted Successfully\n";
				}
				else
				{
					cout<<"Record Doesn't Exit\n";
				}
				break;
			}
			case EXIT:
			{
				bIsExit = true;
				break;
			}
			default:
			{
				break;
			}
		}
	}
}

void main()
{
	long int size = 0;
	cout<<"Enter the length of the Hash Table\n";
	cin>>size;

	MyHashTable *hashTable = new MyHashTable(size);
	hashTable->init();
	
	delete hashTable;

	getch();
}