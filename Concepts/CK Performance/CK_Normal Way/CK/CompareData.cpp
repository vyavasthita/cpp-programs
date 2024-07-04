#include "CompareData.h"
#include <iostream>
#include <vector>
#include <map>


using namespace std;

CompareData::CompareData(CSVData* const oCSVData) : moCSVData(oCSVData)
{
}

void CompareData::ProceedForComparision()
{
	map<int, vector<string> > csvMap = moCSVData->getCSVData();
	
	map<int, bool> tcMap = moCSVData->getTCData();
}