#include <iostream>
#include <conio.h>

using namespace std;


union myunion
{
	char ch;
	int i;
	double d;
};

void main()
{
	union myunion un;

	un.i = 65;

	//cout<<"Value of i is : "<<un.i<<endl;
	cout<<"Value of ch is : "<<un.ch<<endl;
	getch();
}