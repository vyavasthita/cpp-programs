#include "CSVParser.h"

using namespace std;

CSVParser::CSVParser(CSVData* const oCSVData) : moCSVData(oCSVData)
{
}

void CSVParser::ReadCSVFile()
{
	string vecValue = "Dilip";
	vector<string> v;
	map<int, vector<string> > m;

	for(int i = 0; i < 10; i++)
	{
		v.push_back(vecValue);
	}

	for(int i = 0; i < 20000; i++)
	{
		m.insert(make_pair(i, v));
	}

	moCSVData->setCSVData(m);
}