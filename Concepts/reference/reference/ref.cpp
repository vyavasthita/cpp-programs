#include <iostream>
#include <conio.h>

using namespace std;


void main()
{
	int i = 7;
	int j = 5;

	int& iref = i;
	iref = j;

	int* intP;
	int*& ptrRef = intP;

	ptrRef = new int;
	*ptrRef = 5;

	getch();
}