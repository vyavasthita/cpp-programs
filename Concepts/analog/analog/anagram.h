#include <iostream>
#include "hash_table.h"

#ifndef __ANA_H_
#define __ANA_H_

	class CAnagram
	{
		public:
			CAnagram(){}
			
			~CAnagram(){};

			void removeDelimiter(std::vector<std::string> & vecWords);

			int NumberOfAnagrams(std::string& inputStr);


		private:
			MyHashTable m_hashTable;
	};



#endif __ANA_H_