#include "Light.h"
#include "Fan.h"
#include "Switch.h"

using namespace DesignPattern;

void main()
{
	CSwitch *poFancySwitch  = new CFancySwitch();
	CSwitch *poNormalSwitch  = new CNormalSwitch();

	CElectricalEquipment *poFan = new CFan();

	poFancySwitch->m_poElecEquipment = poFan; 

	poFancySwitch->On();
	poFancySwitch->Off();

	poNormalSwitch->m_poElecEquipment = poFan;
}