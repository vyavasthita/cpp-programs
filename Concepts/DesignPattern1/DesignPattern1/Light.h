#ifndef __LIGHT_
#define __LIGHT_

#include "ElectricalEquipment.h"

namespace DesignPattern
{
	class CLight:public CElectricalEquipment
	{
		public:
			virtual void PowerOn();
			virtual void PowerOff();
	};
};

#endif __LIGHT_