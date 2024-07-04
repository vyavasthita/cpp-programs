#include "CreateJuiceObject.h"
#include "AppleJuiceFactory.h"
#include "MangoJuiceFactory.h"
#include "OrangeJuiceFactory.h"

CJuiceFactory* CCreateJuiceObject::GetJuiceObject(short int nJuiceChoice)
{
	switch(nJuiceChoice)
	{
		case 1:
			pCJuiceFactory = new CMangoJuiceFactory;
			break;
		case 2:
			pCJuiceFactory = new COrangeJuiceFactory;
			break;
		case 3:
			pCJuiceFactory = new CAppleJuiceFactory;
			break;
	}
	return pCJuiceFactory;
}