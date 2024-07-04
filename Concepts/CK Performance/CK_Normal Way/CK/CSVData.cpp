#include "CSVData.h"


void CSVData::setCSVData(map<int, vector<string> >& csvMap)
{
	mCSVMap = csvMap;
}

map<int, vector<string> > CSVData::getCSVData()
{
	return mCSVMap;
}

void CSVData::setTCData(map<int, bool >& tcMap)
{
	mTCMap = tcMap;
}

map<int, bool > CSVData::getTCData()
{
	return mTCMap;
}