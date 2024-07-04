#include <iostream>

namespace HASH_NM
{
	enum e_CHOICE
	{
		INSERT = 1,
		DELETE,
		PRINT,
		COUNT,
		EXIT
	};

	struct st_Hash
	{
		int value;
		struct st_Hash *next;
	};

	class HashTable
	{
		public:
			HashTable();
			~HashTable();

			void IntitializeHashTable();
			int GetHash(int value);

			void InsertItem(int item);
			void DeleteItem(int item);
			void PrintItem();
			int CountItems();
		private:
			int m_size;
			st_Hash *HashArray;
			st_Hash *start;
	};
};