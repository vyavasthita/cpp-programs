#include "CompareData.h"
#include <iostream>
#include <vector>
#include <map>


using namespace std;
void CompareData::setCSVData(int& key, vector<string>& value)
{
	mCSVMap.insert(make_pair(key, value));
}
void CompareData::setTCData(int& key, bool& value)
{
	mTCMap.insert(make_pair(key, value));
}
//
//CompareData::CompareData(CSVData* const oCSVData) : moCSVData(oCSVData)
//{
//}

void CompareData::ProceedForComparision()
{
	
}