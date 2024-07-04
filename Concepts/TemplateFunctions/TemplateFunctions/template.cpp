#include <iostream>
#include <conio.h>

using namespace std;


template <typename T > int addNum(T& a, T& b)
{
	T res = a + b;
	return res;
}

int addNum(int a, int b)
{
	int res = a - b;
	return res;
}

void main()
{
	int i = 5, j = 7;
	int res = addNum(i, j);
	cout << res;
	getch();
}