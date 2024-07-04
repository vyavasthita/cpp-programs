#pragma once

#include <iostream>

typedef struct MatrixCapacity
{
	int rowCapacity;
	bool bFull;
}CAPACITY;


class Sodoku
{
	public:
		Sodoku(int size);
		~Sodoku();

		bool addNumber(int rowNumber, int columnNumber, int number);
		bool isMatrixFull(int rowNumber);
		bool isMatrixRowFull(int rowNumber);
		void updateMatrixCapacity(int rowNumber);
		bool validateNumber(int number);
		bool validateRow(int rowNumber);
		bool validateColumn(int columnNumber);
		bool validateInnerMatrix(int number, int rowNumber, int columnNumber);
		int getSquareRoot(int number);
		void showResult();

	private:
		const int m_nMatrixSize;
		int m_nMaxSizeOfNumber;
		int m_nInnerMatrixSize;		

		int ** m_nPtrMatrix;
		bool m_bMatrixFull;

		int m_nMatrixCapacity;

		CAPACITY* m_capacity;
};