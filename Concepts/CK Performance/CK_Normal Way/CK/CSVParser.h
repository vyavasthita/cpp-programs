#ifndef CSV_PAR
#define CSV_PAR

#include <iostream>
#include <vector>
#include <map>
#include "CSVData.h"


class CSVParser
{
	public:
		//CSVParser(){}
		~CSVParser(){}
		CSVParser(CSVData* const oCSVData);
		void ReadCSVFile();

	private:
		CSVData* moCSVData;
};

#endif CSV_PAR