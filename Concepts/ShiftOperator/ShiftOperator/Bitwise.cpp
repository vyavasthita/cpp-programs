#include <iostream>
#include <conio.h>

using namespace std;

typedef unsigned char byte;

void main()
{
	byte b1 = 4;
	byte b2 = 16;

	short s = b1|b2;
	short s2 = s<<8;
	cout<<"Short is : "<<s2;

	getch();
}