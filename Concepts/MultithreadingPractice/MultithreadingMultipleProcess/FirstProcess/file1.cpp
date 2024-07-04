#include "file1.h"

First::First(const char* name) :
	m_pcMutexName(name), m_hMutexHandle(NULL)
{

}

void First::CreateMyMutex()
{
	m_hMutexHandle = CreateMutex(NULL, FALSE, m_pcMutexName);
}


HANDLE First::getMutexHandle()
{
	return m_hMutexHandle;
}

void First::runApp()
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
	First first("mymutex");
	first.CreateMyMutex();
	first.runApp();
}