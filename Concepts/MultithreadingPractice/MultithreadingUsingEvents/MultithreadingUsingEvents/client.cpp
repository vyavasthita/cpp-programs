#include <conio.h>
#include <fstream>
#include <iostream>
#include <Windows.h>


using namespace std;

const char* m_FilePath = "C:\\Raja\\TechnicalStudy\\Source_Code\\CPP_Source_Code\\Visual Studio 2015\\MultithreadingUsingEvents\\sample.txt";
HANDLE h_fileEvent;


void writeToFile(const char* name)
{
	cout << "writeToFile()\n";
	ofstream f;

	f.open(m_FilePath, std::ios::app);

	if (f.good())
	{
		f << "Thread " << name << " has written to file.\n";
	}
	else
	{
		cout << "File could not be opened\n";
	}
	f.close();
}

void threadStartRoutine(char *name)
{
	DWORD wait = ::WaitForSingleObject(h_fileEvent, INFINITE);
	
	switch (wait)
	{
		case WAIT_OBJECT_0:
			writeToFile(name);
			break;
		default:
			cout << "An Error occurred for " << name << ":" << GetLastError() << ":\n";
			break;
	}
}


int main()
{
	const int threadCount = 4;
	char* names [threadCount] = {"Raja", "Kannu", "Shilpa", "Goolu"};
	DWORD threadID[threadCount];
	HANDLE m_hThreadHandle[threadCount];
	
	h_fileEvent = ::CreateEvent(NULL, TRUE, FALSE, "temp_event");

	for (int i = 0; i < threadCount; i++)
	{
		m_hThreadHandle[i] = ::CreateThread(NULL, 0, LPTHREAD_START_ROUTINE(&threadStartRoutine), names[i], 0, &threadID[i]);
	}

	writeToFile("Main");
	::SetEvent(h_fileEvent);
	
	DWORD wait = ::WaitForMultipleObjects(threadCount, m_hThreadHandle, TRUE, INFINITE);

	switch (wait)
	{
		case WAIT_OBJECT_0:
			cout << "All Child thread are non signaled.\n";
			break;
		default:
			cout << "WaitForMultipleObjects() failed.\n";
			break;
	}

	::CloseHandle(h_fileEvent);
	//_getch();
	return 0;
}