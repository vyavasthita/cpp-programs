#include "SamsungFactory.h"
#include "Phone.h"
#include "Basic.h"
#include "Smart.h"
#include "Multimedia.h"

//
//Phone* SamsungFactory::getBasicPhone()
//{
//	return new Basic();
//}

Phone* SamsungFactory::getMultimediaPhone()
{
	return new Smart();
}
