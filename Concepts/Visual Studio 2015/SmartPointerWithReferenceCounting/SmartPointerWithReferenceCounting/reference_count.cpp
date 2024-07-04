#include "reference_count.h"

ReferenceCount::ReferenceCount()
{
	count = 0;
}

void ReferenceCount::incrementCount()
{
	++count;
}

void ReferenceCount::decrementCount()
{
	--count;
}

int ReferenceCount::getCount()
{
	return count;
}