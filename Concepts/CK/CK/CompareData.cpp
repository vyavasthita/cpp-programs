#include "CompareData.h"
#include <iostream>
#include <vector>
#include <map>
#include "CSVParser.h"


using namespace std;
void CompareData::setCSVData(int& key, vector<string>& value)
{
	mCSVMap.insert(make_pair(key, value));
}
void CompareData::setTCData(int& key, bool& value)
{
	mTCMap.insert(make_pair(key, value));
}

CompareData::CompareData(CSVData* const oCSVData) : moCSVData(oCSVData)
{
}

void CompareData::ProceedForComparision()
{
	map<int, vector<string> >::iterator ITCSV;
	ITCSV = mCSVMap.begin();

	map<int, bool >::iterator ITTC;
	ITTC = mTCMap.begin();

	for(ITCSV; ITCSV != mCSVMap.end(); ITCSV)
	{
		ITTC = mTCMap.find(ITCSV->first);
		if(ITTC != mTCMap.end())
		{
		}
	}
}