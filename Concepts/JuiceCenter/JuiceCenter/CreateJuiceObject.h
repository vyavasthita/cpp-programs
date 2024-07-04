#include <iostream>
#include "JuiceFactory.h"

#ifndef __CREATE_JUICE_OBJECT
#define __CREATE_JUICE_OBJECT

class CCreateJuiceObject
{
	public:
		CJuiceFactory* GetJuiceObject(short int nJuiceChoice);
	private:
		CJuiceFactory* pCJuiceFactory;
};

#endif __CREATE_JUICE_OBJECT