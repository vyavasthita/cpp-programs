#include "dkvector.h"

template <typename T> CDKVector<T>::CDKVector() : vectorSize(0)
{
	vecDataType = new T[vectorSize];
}

template <typename T> CDKVector<T>::CDKVector(int size) : vectorSize(size)
{
	vecDataType = new T[vectorSize];

	setVectorDefaultValues();
}

template <typename T> CDKVector<T>::~CDKVector()
{
	freeVector();
}

template <typename T> void CDKVector<T>::setVectorDefaultValues()
{
	for (int iIterator = 0; iIterator < vectorSize; iIterator++)
	{
		vecDataType[iIterator] = 0;
	}
}

template <typename T> void CDKVector<T>::freeVector()
{
	delete [] vecDataType;
}

template <typename T> void CDKVector<T>::append(T element)
{
	//vectorSize += 1;
	int iIterator = 0;

	T* vecDataTypeTemp = new T[vectorSize + 1];

	for (iIterator = 0; iIterator < vectorSize; iIterator++)
	{
		vecDataTypeTemp[iIterator] = vecDataType[iIterator];
	}

	vecDataTypeTemp[iIterator] = element;

	freeVector(vecDataType);

	vecDataType = vecDataTypeTemp;
	vecDataTypeTemp = NULL;
}

template <typename T> int CDKVector<T>::size()
{
	return vectorSize;
}

template <typename T> void CDKVector<T>::operator()(T& size)
{
}

void main()
{
	CDKVector<int> dkvector1;
	CDKVector<int> dkvector2(10);

	dkvector1.append(1);
}

