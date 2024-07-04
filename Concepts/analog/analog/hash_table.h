#ifndef __HASH_H_
#define __HASH_H_

#include <iostream>


	struct st_Record
	{
		std::string value;
		struct st_Record* next;
	};

	class MyHashTable
	{
		public:
			MyHashTable();
			
			~MyHashTable();

			void init();

			int hash(std::string& word);
			void insertRecord(std::string& record);

			void searchRecord();

			int NumberOfAnagrams();

		private:
			struct st_Record* arrRecord;
			struct st_Record* ptr;
			const int mi_Size;
	};



#endif __HASH_H_