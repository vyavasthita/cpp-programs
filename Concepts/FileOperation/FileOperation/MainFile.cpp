#include "file.h"
#include <conio.h>

void main()
{
	MyFile ob;
	ob.openFile();
	ob.writeToFile("1000");
	ob.writeToFile("2000");
	ob.readFile();

	

	getch();
}