#pragma once

#include <iostream>

class ReverseString
{
	public:
		ReverseString(std::string input);
		void insertItem(char item);
		int getHashKey(char item);

		std::string getReversedInput();

	private:		
		std::string m_strInput;
		int m_nInputSize;		

		char* m_cpItems;
		int m_nItemSize;		

		int m_nHashTableCurrPos;
};
