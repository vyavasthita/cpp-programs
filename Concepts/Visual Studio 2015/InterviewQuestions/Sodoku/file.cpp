#include "file.h"


Sodoku::Sodoku(int size) : 
	m_nMatrixSize(size), m_nMaxSizeOfNumber(size),
	m_bMatrixFull(false), m_nMatrixCapacity(0)
{
	// Fill Matrix
	m_nPtrMatrix = new int*[m_nMatrixSize];

	for (int i = 0; i < m_nMatrixSize; i++)
	{
		m_nPtrMatrix[i] = new int[m_nMatrixSize];

		for (int j = 0; j < m_nMatrixSize; j++)
		{
			m_nPtrMatrix[i][j] = 0;
		}
	}

	m_capacity = new CAPACITY[m_nMatrixSize];

	for (int i = 0; i < m_nMatrixSize; i++)
	{
		m_capacity[i].rowCapacity = 0;
		m_capacity[i].bFull = false;
	}
}

Sodoku::~Sodoku()
{
	for (int i = 0; i < m_nMatrixSize; i++)
	{
		delete [] m_nPtrMatrix[i];
		m_nPtrMatrix[i] = NULL;
	}

	delete [] m_nPtrMatrix;
	m_nPtrMatrix = NULL;
}

int Sodoku::getSquareRoot(int number)
{

}

bool Sodoku::isMatrixFull(int rowNumber)
{
	return m_bMatrixFull;
}

bool Sodoku::isMatrixRowFull(int rowNumber)
{
	if (m_capacity[rowNumber].bFull)
	{
		return true;
	}
	return false;
}

void Sodoku::updateMatrixCapacity(int rowNumber)
{
	if (m_bMatrixFull)
		return;

	if (!m_capacity[rowNumber].bFull)
	{
		++m_capacity[rowNumber].rowCapacity;

		if (m_capacity[rowNumber].rowCapacity == m_nMatrixSize)
		{
			m_capacity[rowNumber].bFull = true;
			++m_nMatrixCapacity;
		}
	}

	if (m_nMatrixCapacity == m_nMatrixSize)
	{
		m_bMatrixFull = true;
	}
}

bool Sodoku::addNumber(int rowNumber, int columnNumber, int number)
{
	if (number <= m_nMaxSizeOfNumber)
	{
		if (validateRow(number))
		{
			if (validateColumn(number))
			{
				if (validateInnerMatrix(number, rowNumber, columnNumber))
				{
					if (!isMatrixFull(rowNumber))
					{
						if (!isMatrixRowFull(rowNumber))
						{
							if (m_nPtrMatrix[rowNumber][columnNumber] != 0)
							{
								m_nPtrMatrix[rowNumber][columnNumber] = number;
								updateMatrixCapacity(rowNumber);
								return true;
							}
						}
					}										
				}
			}
		}
	}
	return false;
}

bool Sodoku::validateNumber(int number)
{
	
}

bool Sodoku::validateRow(int rowNumber)
{

}

bool Sodoku::validateColumn(int columnNumber)
{

}

bool Sodoku::validateInnerMatrix(int rowNumber, int columnNumber)
{

}