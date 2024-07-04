#ifndef __SWITCH_
#define __SWITCH_

#include <iostream>
#include "ElectricalEquipment.h"

namespace DesignPattern
{
	class CSwitch
	{
		public:
			void On()
			{
				m_poElecEquipment->PowerOn();
			}
			void Off()
			{
				m_poElecEquipment->PowerOff();
			};

		public:
			CElectricalEquipment *m_poElecEquipment;
	};

	class CNormalSwitch:public CSwitch
	{
		public:
			void On();
			void Off();
	};

	class CFancySwitch:public CSwitch
	{
		public:
			void On();
			void Off();
	};
};

#endif __SWITCH_