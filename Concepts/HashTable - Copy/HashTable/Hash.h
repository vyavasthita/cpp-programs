#ifndef __HASH_H_
#define __HASH_H_

#include <iostream>

namespace NSHashTable
{
	enum e_choice
	{
		INSERT = 1,
		SEARCH,
		EXIT
	};

	struct st_Record
	{
		std::string value;
		struct st_Record* next;
	};

	class MyHashTable
	{
		public:
			MyHashTable();
			MyHashTable(long int size);
			~MyHashTable();

			void init();

			int hash(std::string str);
			void insertRecord(std::string record);
			bool searchRecord(std::string record);

		private:
			struct st_Record* arrRecord;
			struct st_Record* ptr;
			unsigned int mi_Size;
	};
};


#endif __HASH_H_