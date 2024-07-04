#pragma once
#include <iostream>


namespace NamespaceCountChar
{
	typedef struct CharInfo
	{
		char identity;
		short count;
	}INFO;

	class CountChar
	{
		public:
			CountChar();
			short getHashKey(char cChar);
			void insertCharInfo(char cChar);
			short fetchCharCount();
		private:
			INFO* m_cCharsDetails;
	};
};
