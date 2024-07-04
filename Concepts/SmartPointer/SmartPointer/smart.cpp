#include "smart.h"


template <typename T> SmartPointer<T>::SmartPointer() : m_pPointer(NULL)
{
	
}

template <typename T> SmartPointer<T>::~SmartPointer()
{
	delete m_pPointer;

	m_pPointer = NULL;
}

template <typename T> void SmartPointer<T>::SmartPointer(T* ptr)
{
	m_pPointer = ptr;
}

template <typename T> T* SmartPointer<T>::release()
{
	T* tempPtr = NULL;

	tempPtr = m_pPointer;

	m_pPointer = NULL;

	return tempPtr;
}