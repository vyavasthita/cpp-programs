#include <iostream>
#include <sstream>
#include <conio.h>

using namespace std;

void main()
{
	char* arr = "I love c++ programing\n";
	int i = 22;
	cout.write(arr, i);

	cout.put(arr[5]);

	ostringstream ostream;
	char*ptr = "hi	how	are	you ?";

	getch();
}