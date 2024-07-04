#include "templatefile.h"

void main()
{
	{
		MyTemplate<int, 7> temp;
		temp.printValues();

		MyTemplate<int, 7> temp2(temp);
		temp2.printValues();
	}
	getch();
}