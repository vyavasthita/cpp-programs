#ifndef CMP_DATA
#define CMP_DATA

#include "CSVData.h"

class CompareData
{
	public:
		CompareData(){}
		~CompareData(){}
		//CompareData(CSVData* const oCSVData);
		void ProceedForComparision();

	private:
		CSVData* moCSVData;

	public:
	void setCSVData(int&, vector<string>&);

	void setTCData(int&, bool&);

	private:
		map<int, vector<string> > mCSVMap;
		map<int, bool > mTCMap;

};
#endif CMP_DATA