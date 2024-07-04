#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

void main()
{
	ofstream ostream;
	ostream.open("C:\\Dilip Data\c++\\myfile.txt");

	if (ostream.good())
	{
		cout << "file opened successfully\n";
	}
	ostream.close();

	getch();
}