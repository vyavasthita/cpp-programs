#include <iostream>
#include <conio.h>

using namespace std;

// This is a function template.
template <class family> void swapargs(family &a, family &b)
{
	family temp;
	temp = a;
	a = b;
	b = temp;
}
int main()
{
	int i = 10, j = 20;
	double x = 10.1, y = 23.3;
	
	char a = 'x', b = 'z';

	cout << "Original i, j: " << i << ' ' << j << '\n';
	cout << "Original x, y: " << x << ' ' << y << '\n';
	cout << "Original a, b: " << a << ' ' << b << '\n';

	swapargs(i, j); // swap integers
	swapargs(x, y); // swap floats
	swapargs(a, b); // swap chars

	cout<<"\nAfter Swaping :-> \n\n";

	cout << "Swapped i, j: " << i << ' ' << j << '\n';
	cout << "Swapped x, y: " << x << ' ' << y << '\n';
	cout << "Swapped a, b: " << a << ' ' << b << '\n';

	getch();
	return 0;
}