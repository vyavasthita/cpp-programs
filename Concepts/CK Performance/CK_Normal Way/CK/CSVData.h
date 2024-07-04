#ifndef CSV_DATA
#define CSV_DATA

#include <vector>
#include <map>

using namespace std;

class CSVData
{
	public:
		void setCSVData(map<int, vector<string> >&);
		map<int, vector<string> > getCSVData();

		void setTCData(map<int, bool >&);
		map<int, bool > getTCData();

	private:
		map<int, vector<string> > mCSVMap;
		map<int, bool > mTCMap;
};

#endif CSV_DATA

