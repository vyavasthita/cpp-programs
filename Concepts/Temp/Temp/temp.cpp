#include <iostream>
#include <conio.h>
#include <string>

using namespace std;


void main()
{	
	string str = "Dilip Kumar Sharma";
	int TableSize = 9;

	unsigned long int ln = 0;

	if (str.size() > 0)
	{	
		ln = str.at(0);
	}

	for (int i = 0; i < str.size(); i++)
	{
		ln = (ln << 4);
		ln +=  + str.at(i);
	}

	int key = ln % TableSize;


	getch();
}	