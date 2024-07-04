#include <iostream>
#include <conio.h>

int addNum(int i, int j)
{
	int temp;
	temp = i + j;

	return temp;
}

void main()
{
	int (*fptr) (int, int) = &addNum;

	std::cout << fptr(5, 7);

	getch();
}