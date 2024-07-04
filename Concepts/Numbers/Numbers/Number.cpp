#include "Number.h"


int NumToWord::siIndexNumber = 0;

NumToWord::NumToWord() : miNumber(0), miLength(0), mstrWord("")
{
}

NumToWord::~NumToWord()
{
}

void main()
{
	NumToWord mNumToWord;
	mNumToWord.askNumber();
	mNumToWord.proceed();

	getch();
}

void NumToWord::askNumber()
{
	cout<<"Enter A Number : ";
	cin>>miNumber;

	setLength(miNumber);
}

int NumToWord::getLength()
{
	return (miLength);
}

void NumToWord::setLength(long int liNumber)
{
	int length = 0;
	while(liNumber)
	{
		liNumber = liNumber/10;
		++length;
	}
	miLength = length;
	siIndexNumber = miLength;
}

void NumToWord::proceed()
{
	unsigned short usIndexNum = 0;

	while(siIndexNumber)
	{
		usIndexNum = getIndexNum(siIndexNumber);
		convertToWord(usIndexNum);
		--siIndexNumber;
	}	
}

unsigned short NumToWord::getIndexNum(int index)
{
	long int liDivisor = 0;
	unsigned short usIndexNum = 0;
	long int liNum = miNumber;

	switch(index)
	{
		case 1:
		{
			liDivisor = liNum * 1;
			break;
		}
		case 2:
		{
			liDivisor = liNum * 10;
			break;
		}
		case 3:
		{
			liDivisor = liNum * 100;
			break;
		}
		case 4:
		{
			liDivisor = liNum * 1000;
			break;
		}
	}

	usIndexNum = liNum/liDivisor;
	return (usIndexNum);
}

void NumToWord::convertToWord(unsigned short usNum)
{
	string strTmpString = "";

	switch(usNum)
	{
		case UNIT::ONE:
		{
			strTmpString = "One";
			break;
		}
		case UNIT::TWO:
		{
			strTmpString = "Two";
			break;
		}
		case UNIT::THREE:
		{
			strTmpString = "Three";
			break;
		}
		case UNIT::FOUR:
		{
			strTmpString = "Four";
			break;
		}
		case UNIT::FIVE:
		{
			strTmpString = "Five";
			break;
		}
	}

	switch(siIndexNumber)
	{
	}

	mstrWord += strTmpString;
}