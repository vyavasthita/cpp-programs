#include <iostream>
#include "CreateJuiceObject.h"


#ifndef __JUICE_ORDER
#define __JUICE_ORDER

class CJuiceOrder
{
	public:
		void WelcomeToJuiceCenter();
		void ProcessOrder(short int nJuiceChoice);
		void PrepareJuice(CJuiceFactory* poCJuiceFactory);
	private:
		CJuiceFactory* pCJuiceFactory;
		CCreateJuiceObject oCCreateJuiceObject;
};

#endif __JUICE_ORDER