#include "count.h"

CountKPrime::CountKPrime(int start, int end, int k) :
	m_nStart(start), m_nEnd(end), m_nK(k)
{

}

CountKPrime::~CountKPrime()
{

}

bool CountKPrime::isFactorUnique(
	int * npFactors, int nSizeOfFactors, int nNumber)
{
	int index = 0;

	while (nSizeOfFactors--)
	{
		if (npFactors[index++] == nNumber)
		{
			return false;
		}
	}

	return true;
}

bool CountKPrime::isNumberKPrime(int nNumber, const int nK)
{
	int div = 2;
	int existingElementsCount = 0;
	
	m_npDistinctFactors = new int[5];

	while (nNumber != 1)
	{
		if (existingElementsCount > nK)
		{
			return false;
		}

		if ((nNumber % div) == 0)
		{
			if (isFactorUnique(m_npDistinctFactors, existingElementsCount, div))
			{
				m_npDistinctFactors[existingElementsCount++] = div;
			}
			nNumber /= div;
		}
		else
		{
			++div;
		}		
	}

	delete [] m_npDistinctFactors;
	m_npDistinctFactors = NULL;

	if (existingElementsCount == nK)
	{
		return true;
	}

	return false;
}

int CountKPrime::findKPrimes()
{
	int nCountKPrime = 0;

	for (int i = m_nStart; i <= m_nEnd; i++)
	{
		if (isNumberKPrime(i, m_nK))
		{
			++nCountKPrime;
		}
	}
	return nCountKPrime;
}
