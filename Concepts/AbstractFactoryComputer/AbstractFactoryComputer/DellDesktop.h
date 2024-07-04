#include <iostream>
#include "Desktop.h"

#ifndef __DELL_DESK_H_
#define __DELL_DESK_H_

namespace Electronics
{
	class CDellDesktop : public CDesktop
	{
		public:
			virtual void info();
	};
};

#endif __DELL_DESK_H_