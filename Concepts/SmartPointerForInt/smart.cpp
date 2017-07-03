#include "smart.h"

using namespace NamespaceSmartPointerForInt;

// ******************* ReferenceCount ******************* //
ReferenceCount::ReferenceCount()
{
	m_refCount = 0;
}

ReferenceCount::~ReferenceCount()
{

}

void ReferenceCount::incrementCount()
{
	++m_refCount;
}

void ReferenceCount::decrementCount()
{
	--m_refCount;
}

void ReferenceCount::setCount(int count)
{
	m_refCount = count;
}

int ReferenceCount::getCount() const
{
	return m_refCount;
}

SmartPointerForInt::SmartPointerForInt()
{
	m_pSmartPointer = NULL;
}

SmartPointerForInt::SmartPointerForInt(int* ob) : isReleased(false)
{
	m_pSmartPointer = ob;
	oReferenceCount.incrementCount();
	
}

SmartPointerForInt::SmartPointerForInt(const SmartPointerForInt& ob)
{
	if (this != &ob)
	{
		m_pSmartPointer = ob.m_pSmartPointer;
		oReferenceCount.setCount(ob.oReferenceCount.getCount() + 1);
	}
}

SmartPointerForInt::~SmartPointerForInt()
{
	if (isReleased == false)
	{
		oReferenceCount.decrementCount();
	}
	
	if (oReferenceCount.getCount() == 0 && isReleased == false)
	{ 
		delete m_pSmartPointer;
	}
}

int* SmartPointerForInt::get()
{
	return m_pSmartPointer;
}

int SmartPointerForInt::operator * ()
{
	return *m_pSmartPointer;
}

int* SmartPointerForInt::operator -> ()
{
	return m_pSmartPointer;
}

void SmartPointerForInt::release()
{
	m_pSmartPointer = NULL;
	isReleased = true;
	oReferenceCount.decrementCount();
}

/*
int& SmartPointerForInt::operator = (int* ob)
{

}
*/


