#include <iostream>
#include <Windows.h>

using namespace std;

void singleInstance()
{
	HANDLE h = CreateMutex(NULL, false, "one_instance");

	DWORD wait = WaitForSingleObject(h, 0);

	switch (wait)
	{
		case WAIT_OBJECT_0:
			cout << "Instance of Application is Running.\n";
			::Sleep(20000);
			cout << "Instance of Application is Going to be exited.\n";
			::Sleep(2000);
			break;
		default:
			cout << "Instance of Application is Already Running.\n";
			::Sleep(2000);
			break;
	}
}

int main()
{
	singleInstance();
	return 0;
}