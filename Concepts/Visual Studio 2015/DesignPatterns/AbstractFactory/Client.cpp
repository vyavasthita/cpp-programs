#include "PhoneFactory.h"
#include "MotoFactory.h"
#include "SamsungFactory.h"
#include "SonyFactory.h"
#include "Phone.h"
#include <conio.h>

using namespace std;


int main()
{
	PhoneFactory* factory = new SamsungFactory;
	cout << factory->getBasicPhone();
	_getch();
	return 0;
}