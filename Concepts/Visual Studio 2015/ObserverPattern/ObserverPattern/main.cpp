#include "observer.h"
#include "subject.h"
#include <conio.h>

int main()
{
	ComputerDistributor distributor;

	RamComputers* opRam = new RamComputers;

	distributor.Register(opRam);

	distributor.Notify();

	distributor.UnRegister(opRam);

	RahimComputers* opRahim = new RahimComputers;

	distributor.Register(opRahim);

	distributor.UnRegister(opRahim);

	distributor.Notify();

	_getch();
	return 0;
}