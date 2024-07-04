#include <iostream>
#include <conio.h>
#include "file.h"
#include <time.h>


using namespace std;


int main()
{
	time_t rawtime;

	struct tm* timeinfo;

	time(&rawtime);

	timeinfo = localtime(&rawtime);

	long callTime = timeinfo->tm_hour;

	cout << callTime;

	_getch();

	return 0;
}