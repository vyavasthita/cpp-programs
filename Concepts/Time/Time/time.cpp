#include <iostream>
#include <conio.h>
#include <ctime>

using namespace std;
void main()
	{
		time_t now = time(0);
		char* dt = ctime(&now);
		 cout << "The local date and time is: " << dt << endl;

		getch();
	}