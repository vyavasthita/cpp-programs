#include "file2.h"


Second::Second(const char* name) :
	m_pcMutexName(name), m_hMutexHandle(NULL)
{

}

void Second::runApp()
{
	DWORD d = WaitForSingleObject(m_hMutexHandle, INFINITE);

	switch (d)
	{
		case WAIT_OBJECT_0:
			cout << "App is running.\n";
			Sleep(10000);
		default:
			cout << "One instance of App is already running.\n";
			break;
	}
}

int main()
{
	Second second("mymutex");
	second.runApp();
}