#include <iostream>
#include "Desktop.h"

#ifndef __HCL_DESK_H_
#define __HCL_DESK_H_

namespace Electronics
{
	class CHCLDesktop : public CDesktop
	{
		public:
			virtual void info();
	};
};

#endif __HCL_DESK_H_