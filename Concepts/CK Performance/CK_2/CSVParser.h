#ifndef CSV_PAR
#define CSV_PAR

#include <iostream>
#include <vector>
#include <map>
#include "CSVData.h"
#include "CompareData.h"


class CSVParser
{
	public:
		//CSVParser(){}
		~CSVParser(){}
		CSVParser(CompareData* const oCMPData);
		void ReadCSVFile();

	private:
		CompareData* moCMPData;
};

#endif CSV_PAR