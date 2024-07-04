#pragma once

#include "Phone.h"
#include "PhoneFactory.h"

class SamsungFactory : public PhoneFactory 
{
	public:
		virtual Phone* getSmartPhone();
		virtual Phone* getMultimediaPhone();
		virtual Phone* getBasicPhone();
};
