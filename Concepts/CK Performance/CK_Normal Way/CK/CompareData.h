#ifndef CMP_DATA
#define CMP_DATA

#include "CSVData.h"

class CompareData
{
	public:
		CompareData(){}
		~CompareData(){}
		CompareData(CSVData* const oCSVData);
		void ProceedForComparision();

	private:
		CSVData* moCSVData;
};
#endif CMP_DATA