#include "SonyFactory.h"
#include "Phone.h"
#include "Basic.h"
#include "Smart.h"
#include "Multimedia.h"


Phone* SonyFactory::getBasicPhone()
{
	return new Basic();
}

Phone* SonyFactory::getMultimediaPhone()
{
	return new Multimedia();
}

Phone* SonyFactory::getSmartPhone()
{
	return new Smart();
}