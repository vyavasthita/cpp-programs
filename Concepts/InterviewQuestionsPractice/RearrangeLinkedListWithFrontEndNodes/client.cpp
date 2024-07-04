#include "file.h"
#include <conio.h>

using namespace LINKEDLIST;


int main()
{
	LinkedList list(10);
	list.rearrangeNodes();
	list.print();

	_getch();
	return 0;
}