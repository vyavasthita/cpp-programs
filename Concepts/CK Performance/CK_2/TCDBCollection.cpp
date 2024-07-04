#include <iostream>
#include <conio.h>
#include <time.h>
#include "TCDBCollection.h"
#include "CompareData.h"


using namespace std;


void TCDB::fetchTCData()
{
	CSVParser oCSVParser(&moCompareData);
	oCSVParser.ReadCSVFile();

	bool flag = false;

	map<int, bool> t;

	for(int i = 0; i < 20000; i++)
	{
		t.insert(make_pair(i, flag));
		moCompareData.setTCData(i, flag);
	}
}

void main()
{
	TCDB tc;
	clock_t start, end;
	start = clock();
	tc.fetchTCData();
	end = clock();

	cout<<"Execution Time is : "<<(double)(end - start)/CLOCKS_PER_SEC<<" "<<"Seconds";
	getch();
}