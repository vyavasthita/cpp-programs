#include "assign_op.h"
#include <conio.h>

using namespace NamespaceAssignOp;

int main()
{
	//Assignment Operator
	AssignOp ob1(5);

	AssignOp ob2(7);

	ob2 = ob1;

	ob1.print();
	ob2.print();

	_getch();
}