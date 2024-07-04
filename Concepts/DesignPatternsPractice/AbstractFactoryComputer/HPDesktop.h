#include <iostream>
#include "Desktop.h"

#ifndef __HP_DESK_H_
#define __HP_DESK_H_

namespace Electronics
{
	class CHPDesktop : public CDesktop
	{
		public:
			virtual void info();
	};
};

#endif __HP_DESK_H_