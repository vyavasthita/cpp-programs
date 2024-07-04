#include "smartpointer.h"
#include <conio.h>

template <typename T> TCSmartPointer<T>::TCSmartPointer()
{
	//ptValue = new T;
	bReleaseStatus = false;
}

template <typename T> TCSmartPointer<T>::TCSmartPointer(T* value)
{
	//ptValue = new T;
}

template <typename T> TCSmartPointer<T>::~TCSmartPointer()
{
	if (bReleaseStatus == false)
	{
		delete ptValue;
	}
}

template <typename T> void TCSmartPointer<T>::setReleaseStatus(bool bStatus)
{
	bReleaseStatus = bStatus;
}

template <typename T> bool TCSmartPointer<T>::setReleaseStatus()
{
	return bReleaseStatus;
}

template <typename T> void TCSmartPointer<T>::operator = (T* value)
{
	setReleaseStatus(true);
	ptValue = value;
}

template <typename T> T* TCSmartPointer<T>::get()
{
	return ptValue;
}

template <typename T> T* TCSmartPointer<T>::release()
{
	setReleaseStatus(true);

	ptValue = NULL;
}

template <typename T> T TCSmartPointer<T>::operator * ()
{
	return *ptValue;
}

template <typename T> T TCSmartPointer<T>::operator -> ()
{
	return *ptValue;
}

void main()
{
	int* ptr = new int;

	TCSmartPointer<int> smartPointer;

	smartPointer = ptr;	
	

	int *p = smartPointer.release();
	*smartPointer;
	delete p;
	getch();
}