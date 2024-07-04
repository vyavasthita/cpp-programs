#include <iostream>
#include <conio.h>
#include <map>
#include <bitset>

using namespace std;

void main()
{
	map<int, string> m;
	pair<map<int, string>::iterator, bool> pairconfig;
	m.insert(make_pair(1, "one"));

	pairconfig = m.insert(make_pair(1, "one"));
	if (pairconfig.second == false)
	{
		cout << "duplicate element -> " << '\"' + pairconfig.first->first + '\"' << " " << "found in map." << endl;
	}
	
	bitset<10> bit;

	getch();
}