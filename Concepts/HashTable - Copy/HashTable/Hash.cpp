#include "Hash.h"
#include <conio.h>
#include <assert.h>
#include <string>

using namespace NSHashTable;
using namespace std;

#define NIL ""

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
		arrRecord[iIterator].value = "";
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

int MyHashTable::hash(std::string str)
{
	int key = 0;
	
    unsigned h = 0;

	for ( int i = 0; i < str.length(); ++i )
    {
        h = h + str[ i ];
    }
	key = h % mi_Size;
	return key;
}

void MyHashTable::insertRecord(std::string record)
{
	long int key = hash(record);
	ptr = arrRecord + key;

	if(ptr->value.compare(NIL) == 0)
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

bool MyHashTable::searchRecord(std::string record)
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

void MyHashTable::init()
{
	unsigned short usChoice = 0;
	bool bIsExit = false;
	string strRecord;
	bool bIsRecordFound = false;

	while(!bIsExit)
	{
		cout<<"*****Hash Table*****\n\n";
		cout<<"1. Insert A Record\n";
		cout<<"2. Search A Record\n";
		cout<<"3. Exit\n";

		cin>>usChoice;

		switch(usChoice)
		{
			case INSERT:
			{
				cout<<"Enter A Record to insert\n";
				cin>>strRecord;

				insertRecord(strRecord);
				break;
			}
			case SEARCH:
			{
				cout<<"Enter A Record to search\n";
				cin>>strRecord;

				bIsRecordFound = searchRecord(strRecord);
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