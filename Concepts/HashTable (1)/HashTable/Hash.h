#ifndef __HASH_H_
#define __HASH_H_

#include <iostream>

namespace NSHashTable
{
	enum e_choice
	{
		INSERT = 1,
		SEARCH,
		DELETE,
		EXIT
	};

	struct st_Record
	{
		int value;
		struct st_Record* next;
	};

	class MyHashTable
	{
		public:
			MyHashTable();
			MyHashTable(long int size);
			~MyHashTable();

			void init();

			int hash(long int& number);
			void insertRecord(long int& record);
			bool deleteRecord(long int& record);
			bool searchRecord(long int& record);

		private:
			struct st_Record* arrRecord;
			struct st_Record* ptr;
			int mi_Size;
	};
};


#endif __HASH_H_