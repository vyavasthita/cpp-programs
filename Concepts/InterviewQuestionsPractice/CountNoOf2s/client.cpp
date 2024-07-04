#include "file.h"
#include <conio.h>

using namespace std;


int main()
{
	TwoCount oTwoCount;
	int count = oTwoCount.countTwos(221);

	cout << "Count of 2s is : " << count << endl;

	_getch();
	return 0;
}