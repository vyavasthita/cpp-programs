#include <iostream>
#include <conio.h>

using namespace std;

void main()
{
	int i = 64;

	int j = i << 4;

	cout << "64 left shilft by 4 -> " << j << endl;

	i = 15;
	int k = i << 2;
	cout << "15 left shilft by 2 -> " << k << endl;

	i = 15;
	int l = i >> 2;
	cout << "15 right shilft by 2 -> " << l << endl;

	getch();
}