#include "ReferenceCount.h"



ReferenceCount::ReferenceCount() : m_nRefCount(0)
{
	
}

ReferenceCount::~ReferenceCount()
{
}

void ReferenceCount::setReferenceCount(int count)
{
	m_nRefCount = count;
}

int ReferenceCount::getReferenceCount()
{
	return m_nRefCount;
}

void ReferenceCount::incrementRefCount()
{
	++m_nRefCount;
}

void ReferenceCount::decrementRefCount()
{
	--m_nRefCount;
}
