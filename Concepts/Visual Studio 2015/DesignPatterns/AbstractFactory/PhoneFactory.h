#pragma once
#include <iostream>
#include "Phone.h"

class PhoneFactory
{
	public:
		virtual Phone* getSmartPhone() = 0;
		virtual Phone* getMultimediaPhone() = 0;
		virtual Phone* getBasicPhone() = 0;
};
