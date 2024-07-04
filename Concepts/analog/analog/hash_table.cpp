#include "hash_table.h"
#include <conio.h>
#include <assert.h>

using namespace std;


MyHashTable::MyHashTable() : mi_Size(200)
{
	ptr = NULL;

	arrRecord = new struct st_Record[mi_Size];

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

int MyHashTable::hash(std::string& word)
{
	int key = 0;

	unsigned long hash = 0;
	
	for (unsigned int iIterator = 0; iIterator < word.size(); iIterator)
	{
		hash = hash*iIterator + word[iIterator];
	}

	return (hash % key);
}

void MyHashTable::insertRecord(std::string& record)
{
	long int key = hash(record);
	ptr = arrRecord + key;

	if((ptr->value).compare("") == 0)
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
}

int MyHashTable::NumberOfAnagrams()
{
	struct st_Record* ptrRecord;
	struct st_Record* ptrTraverseList;

	int noOfAnagrams = 0;
	
	for(int iIterator = 0; iIterator < mi_Size; ++iIterator)
	{
		ptrRecord = arrRecord + iIterator;

		if(ptrRecord->next != NULL)
		{
			while(ptrTraverseList)
			{
				noOfAnagrams++;
				ptrTraverseList = ptrTraverseList->next;
			}
		}
	}

	return noOfAnagrams;
}