#include <iostream>
#include <conio.h>

using namespace std;


int fun(int, float);
void pToFun(int (*ptr)(int, float));



int fun(int a, float b)
{
	cout<<"Function\n";
	return 1;
}

void pToFun(int (*ptr)(int, float))
{
	(*ptr)(5, 7);
}
void main()
{
	int (*p)(int, float) = &fun;
	pToFun(p);
	getch();
}