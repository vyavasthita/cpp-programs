#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

void main()
{
	int intArray[10];

	for(unsigned int ui = 0; ui < 10; ui++)
	{
		intArray[ui] = ui + 1;
		cout<<intArray[ui]<<"\n";
	}
	getch();
}