// Function Overloading

#include <iostream>
#include <conio.h>

using namespace std;


void fun(int a)
{
	cout<<"Integer\n";
}

void fun(double a)
{
	cout<<"Double\n";
}

void fun(char a)
{
	cout<<"Char\n";
}

void main()
{
	//fun(5);
	//fun(5.5);
	fun('A');
	getch();
}