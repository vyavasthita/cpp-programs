#include <iostream>
#include <conio.h>

using namespace std;

enum UNIT
{
	ONE = 1,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE
};

enum NUM
{
	HUNDRED = 3,
	THOUSAND_UNIT,
	THOUSAND_TEN,
	LAKH_UNIT,
	LAKH_TEN,
	CRORE_UNIT,
	CRORE_TEN
};

class NumToWord
{
	public:
		NumToWord();
		~NumToWord();

		void askNumber();
		void setLength(long int);
		int getLength();
		void proceed();
		unsigned short getIndexNum(int);
		void convertToWord(unsigned short usNum);

	private:
		int miNumber;
		int miLength;
		string mstrWord;
		static int siIndexNumber;
};