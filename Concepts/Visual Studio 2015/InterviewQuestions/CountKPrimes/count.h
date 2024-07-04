#pragma once

#include <iostream>


class CountKPrime
{
	public:
		CountKPrime(int start, int end, int k);
		~CountKPrime();

		bool isFactorUnique(int * npFactors, int nSizeOfFactors, int nNumber);
		bool isNumberKPrime(int nNumber, const int nK);

		int findKPrimes();

	private:
		int* m_npDistinctFactors;
		int m_nT;

		int m_nStart;
		const int m_nEnd;
		const int m_nK;
};
