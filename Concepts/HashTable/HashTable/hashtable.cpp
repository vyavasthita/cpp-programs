#include <iostream>
#include <conio.h>

using namespace std;

class HashEntry 
{ 
	private:
      int key; 
      int value; 

	public: 
		HashEntry(){};
		HashEntry(int key, int value) 
		{ 
			this->key = key; 
			this->value = value; 
		}					 
 
		int getKey() 
		{
			return key;  
		}  
		int getValue() 
		{ 
			return value; 
		} 
};

const int TABLE_SIZE = 128;

class HashMap 
{ 
	public:
		HashMap()
		{
			hashTable = new HashEntry[TABLE_SIZE];
		}
		void insertItem(int);
		int getItem(int);
	private:
		HashEntry *hashTable;
};

void HashMap::insertItem(int item)
{
	int hash = item % TABLE_SIZE;
	
}
