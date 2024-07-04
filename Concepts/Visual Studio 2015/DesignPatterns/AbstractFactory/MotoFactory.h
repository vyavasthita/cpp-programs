#pragma once


#include "Phone.h"
#include "PhoneFactory.h"


class MotoFactory : public PhoneFactory
{
	public:
		virtual Phone* getSmartPhone();
		virtual Phone* getMultimediaPhone();
		virtual Phone* getBasicPhone();
};
