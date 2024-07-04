#include <Windows.h>
#include <string>
#include <iostream>

#include "threading.h"
#include "thread_exception.h"

using namespace std;

const short Thread::P_NORMAL = THREAD_PRIORITY_NORMAL;

Thread::Thread() : m_const_cThreadName(""), m_hThread(NULL)
{
}

Thread::Thread(const char* cpThreadName, int count) : m_const_cThreadName(cpThreadName), m_hThread(NULL), m_nCount(count)
{
	setThreadName(m_const_cThreadName);
}

Thread::~Thread()
{
}

void Thread::setThreadName(const char* cpThreadName)
{
	m_const_cThreadName = cpThreadName;
}

void Thread::CreateNewThread()
{
	DWORD threadID;

	m_hThread = (unsigned long*)CreateThread(NULL, 0, LPTHREAD_START_ROUTINE(threadBeginning), this, 0, &threadID);

	if (m_hThread == NULL)
	{
		throw ThreadException("Exception Occurred : Unable to create thread.");
	}
	else
	{
		std::cout << "Thread " << getThreadName() << " " << "created" << std::endl;
	
		setPriority(P_NORMAL);
	}
}

void Thread::run()
{
	for(int i = 0; i < m_nCount; i++) 
	{
		std::cout << getThreadName() << ":" << i + 1 << endl;
	}
	//std::cout << "Thread " << getThreadName() << " " << "started" << std::endl;
}

void Thread::stop()
{
	if(m_hThread == NULL) 
	{
		return;	
	}

	WaitForSingleObject(m_hThread, INFINITE);
	CloseHandle(m_hThread);
	m_hThread = NULL;

	std::cout << "Thread " << getThreadName() << " " << "stopped" << std::endl;
}

void Thread::setPriority(short priority)
{
	SetThreadPriority(m_hThread, priority);
}

const char* Thread::getThreadName() const
{
	return m_const_cThreadName;
}

bool Thread::wait(const char* m, long ms)
{
	HANDLE h = OpenMutex(MUTEX_ALL_ACCESS, FALSE, m);

	if(h == NULL) 
	{
		throw ThreadException("Mutex not found");
	}

	DWORD d = WaitForSingleObject(h, ms);

	switch(d)
	{
		case WAIT_ABANDONED:
			throw ThreadException("Mutex not signaled");
			break;

		case WAIT_OBJECT_0:
			return true;

		case WAIT_TIMEOUT:
			throw ThreadException("Wait timed out");
			break;
	}
	return false;
}

unsigned int threadBeginning(void* param)
{
	Thread* threadObject = (Thread*)param;

	threadObject->run();

	return 0;
}