#ifndef CSV_PAR
#define CSV_PAR

#include <iostream>
#include <vector>
#include <map>
#include "CSVData.h"
#include "CompareData.h"
#include "TCDBCollection.h"


class CSVParser
{
	public:
		CSVParser(){}
		~CSVParser(){}
		CSVParser(CompareData* const oCMPData);
		void ReadCSVFile();

		friend class TCDB;

	private:
		CompareData* moCMPData;
		map<int, vector<string> > m;
};

#endif CSV_PAR