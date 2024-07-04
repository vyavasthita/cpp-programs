#ifndef TC_DB
#define TC_DB

#include <vector>
#include <map>
#include "CSVParser.h"


class TCDB
{
	public:
		void fetchTCData();
	private:
		CompareData moCompareData;
};

#endif TC_DB