#include "copy_ctor.h"
#include <conio.h>

using namespace NamespaceCopyCtor;

int main()
{
	//Copy Ctor
	CopyCtor ob1(5);

	CopyCtor ob2 = ob1;

	ob1.DummyFunForCopyCtorCall(ob1);

	ob1.DummyFunForCopyCtorCall2();
	
	ob1.print();
	ob2.print();

	_getch();
}