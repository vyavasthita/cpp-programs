#include <iostream>
#include <conio.h>

using namespace std;

void main()
{
	const char* str = "Dilip";
	//str[1] = 'I';
		
	char* ch = const_cast<char*>(str);
	
	int* iptr = NULL;
	double* dptr = NULL;

	//dptr = reinterpret_cast<double*>(iptr);

	//double val = reinterpret_cast<double>(dptr);
}