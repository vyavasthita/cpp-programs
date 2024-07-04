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
		CSVData moCSVData;
};

#endif TC_DB