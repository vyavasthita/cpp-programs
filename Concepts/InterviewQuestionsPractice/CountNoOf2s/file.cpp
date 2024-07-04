#include "file.h"

TwoCount::TwoCount()
{
	count = 0;
}


int TwoCount::countTwos(int number)
{
	int digit = 0;

	for (int i = 1; i <= number; i++)
	{
		int n = i;
		while (n != 0)
		{
			digit = n % 10;

			if (digit == 2)
			{
				++count;
			}

			n /= 10;
		}
	}
	return count;
}