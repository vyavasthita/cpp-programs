#include <iostream>
#include <conio.h>

using namespace std;

void addNum(int &a, int &b)
{
	int temp;
	a = 10;
	temp = a + b;
	cout<<"Addition using ref is : "<<temp<<endl;
}

void addNum2(int *a, int *b)
{
	int temp;
	temp = *a + *b;
	cout<<"Addition using pointer is : "<<temp;
}

void main()
{
	int i = 5, j = 7;
	addNum(i, j);
	addNum2(&i, &j);

	cout<<"New value of i is : "<<i<<endl;

	getch();
}