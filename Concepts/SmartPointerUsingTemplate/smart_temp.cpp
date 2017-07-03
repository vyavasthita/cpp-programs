#include "smart_temp.h"

using namespace NamespaceSmartPointerWithTemp;

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





