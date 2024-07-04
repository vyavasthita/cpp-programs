#include "file.h"

Words::Words()
{

}

Words::~Words()
{

}

int Words::getLength(int number)
{
	int length = 0;
	int remainder;

	while (number)
	{
		number /= 10;
		++length;
	}
	return length;
}

int Words::getDivisor(int number)
{
	int length = getLength(number);

	int divisor = 1;

	while (--length)
	{
		divisor *= 10;
	}
	return divisor;
}

const char* Words::getWordForUnit(int number)
{
	switch (number)
	{
		case 1:
			return "One";
			break;
		case 2:
			return "Two";
			break;
		case 3:
			return "Three";
			break;
		case 4:
			return "Four";
			break;
		case 5:
			return "Five";
			break;
		case 6:
			return "Six";
			break;
		case 7:
			return "Seven";
			break;
		case 8:
			return "Eight";
			break;
		case 9:
			return "Nine";
			break;
		case 10:
			return "Ten";
			break;
		case 11:
			return "Eleven";
			break;
		case 12:
			return "Twelve";
			break;
		case 13:
			return "Thirteen";
			break;
		case 14:
			return "Fourteen";
			break;
		case 15:
			return "Fifteen";
			break;
		case 16:
			return "Sixteen";
			break;
		case 17:
			return "Seventeen";
			break;
		case 18:
			return "Eighteen";
			break;
		case 19:
			return "Ninteen";
			break;
		default:
			return "";
			break;
	}
}

const char* Words::getWordForDecimal(int number)
{
	switch (number)
	{
		case 1:
			return "One";
			break;
		case 2:
			return "Twenty";
			break;
		case 3:
			return "Thirty";
			break;
		case 4:
			return "Fourty";
			break;
		case 5:
			return "Fifty";
			break;
		case 6:
			return "Sixty";
			break;
		case 7:
			return "Seventy";
			break;
		case 8:
			return "Eighty";
			break;
		case 9:
			return "Ninety";
			break;
		default:
			return "";
			break;
	}
}

const char* Words::getWordForLength(int number)
{
	switch (number)
	{
		case 1:
			return getWordForUnit(number);
		case 2:
			return getWordForDecimal(number);
		case 3:
			return "Hundred";
		case 4:
			return "Thousand";
		case 5:
			return "Thousand";
		case 6:
			return "Lakh";
		case 7:
			return "Lakh";
		case 8:
			return "Crore";
		case 9:
			return "Crore";
		default:
			return "";
	}
}

const char* Words::getWordsOfNumeric(int number)
{
	int n = 0;
	int divisor = getDivisor(number);

	while (number)
	{
		int n = number / divisor;
	}
}