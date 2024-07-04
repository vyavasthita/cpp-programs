#pragma once

#include <iostream>
#include <conio.h>

using namespace std;


class Words
{
	public:
		Words();
		~Words();

		int getLength(int number);
		int getDivisor(int number);

		const char* getWordForUnit(int number);
		const char* getWordForDecimal(int number);
		const char* getWordForLength(int number);

		const char* getWordsOfNumeric(int number);
};