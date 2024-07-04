#ifndef __FAN_
#define __FAN_

#include "ElectricalEquipment.h"

namespace DesignPattern
{
	class CFan:public CElectricalEquipment
	{
		public:
			virtual void PowerOn();
			virtual void PowerOff();
	};
};

#endif __FAN_