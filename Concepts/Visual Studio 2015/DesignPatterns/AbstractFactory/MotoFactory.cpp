#include "MotoFactory.h"
#include "Phone.h"
#include "Basic.h"
#include "Smart.h"
#include "Multimedia.h"

Phone* MotoFactory::getMultimediaPhone()
{
	return new Smart();
}

Phone* MotoFactory::getBasicPhone()
{
	return new Multimedia();
}
