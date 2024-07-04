#include "mythread.h"
#include <fstream>
#include <time.h>

using namespace std;


void threadStartRoutine(void* ptr)
{
	MyThread* thread = static_cast<MyThread*>(ptr);

	thread->threadStartFunction();
}

MyThread::MyThread(const MyEvent* pcEvent) :
	m_FilePath("C:\\Raja\\TechnicalStudy\\Source_Code\\CPP_Source_Code\\Visual Studio 2015\\MultithreadingUsingEvents\\sample.txt"),
	m_constThreadName("Main Thread"), m_pcEvent(pcEvent)
{
	
}

MyThread::~MyThread()
{
	::CloseHandle(m_hThreadHandle);
	//::DeleteFile(m_FilePath);
}

void MyThread::CreateNewThread(const char* name, int count)
{
	m_constThreadName = name;
	m_nThreadCount = count;
	DWORD threadID;

	m_hThreadHandle = ::CreateThread(NULL, 0, LPTHREAD_START_ROUTINE(&threadStartRoutine), this, 0, &threadID);

	if (m_hThreadHandle == NULL)
	{
		cout << "Thread Could not be created.\n";
	}
	else
	{
		
	}
}

void MyThread::threadStartFunction()
{
	DWORD wait = ::WaitForSingleObject(m_pcEvent->m_hEventHandle, INFINITE);
	
	switch (wait)
	{
	case WAIT_OBJECT_0:
		writeToFile();
		Sleep(2000);
		::SetEvent(m_pcEvent->m_hEventHandle);
		break;
	case WAIT_ABANDONED:
		break;
	case WAIT_TIMEOUT:
		break;
	case WAIT_FAILED:
		break;
	default:
		break;
	}
}

void MyThread::writeToFile()
{
	ofstream f;
	f.open(m_FilePath, std::ios::app);

	if (f.good())
	{
		for (int i = 0; i < m_nThreadCount; i++)
		{
			f << "Thread " << m_constThreadName << " has written to file.\n";
		}
	}
	else
	{
		cout << "File could not be opened\n";
	}
	f.close();
}