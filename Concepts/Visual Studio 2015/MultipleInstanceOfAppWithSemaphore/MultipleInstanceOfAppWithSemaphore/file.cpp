#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>

using namespace std;

int main()
{
	HANDLE h = ::CreateSemaphore(NULL, 2, 2, "temps");
	
	DWORD wait = ::WaitForSingleObject(h, 0);

	switch (wait)
	{
		case WAIT_OBJECT_0:
			cout << "Running\n";
			Sleep(10000);
			::ReleaseSemaphore(h, 1, NULL);
			cout << "Completed\n";
			break;
		// The semaphore was nonsignaled, so a time-out occurred.
		case WAIT_TIMEOUT:
			cout << "Can not run\n";
			break;
		default:
			cout << "Unknown\n";
			break;
	}
	return 0;
}
