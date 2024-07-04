#include "multithreading.h"
#include <string>


const int MyCustomThread::P_ABOVE_NORMAL = THREAD_PRIORITY_ABOVE_NORMAL;
const int MyCustomThread::P_BELOW_NORMAL = THREAD_PRIORITY_BELOW_NORMAL;
const int MyCustomThread::P_HIGHEST = THREAD_PRIORITY_HIGHEST;
const int MyCustomThread::P_IDLE = THREAD_PRIORITY_IDLE;
const int MyCustomThread::P_LOWEST = THREAD_PRIORITY_LOWEST;
const int MyCustomThread::P_NORMAL = THREAD_PRIORITY_NORMAL;
const int MyCustomThread::P_CRITICAL = THREAD_PRIORITY_TIME_CRITICAL;


MyCustomThread::MyCustomThread() : mstrThreadName("")
{
	m_Thread = NULL;
}

MyCustomThread::~MyCustomThread() 
{
	if(m_Thread != NULL) 
	{
		stop();
	}
}

void MyCustomThread::setThreadName(std::string strName)
{
	mstrThreadName = strName;
}

std::string MyCustomThread::getThreadName()
{
	return (mstrThreadName);
}

void MyCustomThread::start()
{
	DWORD dWord = 0;

	m_Thread = (unsigned long*)CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)processThread, (MyCustomThread*)this, 0, &dWord);

	if(m_Thread == NULL)
	{
		throw ThreadException("Failed to create thread");
	}
	else
	{
		setPriority(MyCustomThread::P_NORMAL);
	}
}

void MyCustomThread::setPriority(int priority)
{
	if(m_Thread == NULL) 
	{
		throw ThreadException("Thread object is null");
	}
	else 
	{
		if(SetThreadPriority(m_Thread, priority) == 0) 
		{
			throw ThreadException("Failed to set priority");
		}
	}
}

void MyCustomThread::sleep(long int ms)
{
	Sleep(ms);
}

void MyCustomThread::stop()
{
	if(m_Thread == NULL) 
	{
		return;	
	}

	WaitForSingleObject(m_Thread, INFINITE);
	CloseHandle(m_Thread);
	m_Thread = NULL;
}

unsigned int processThread(void* thread)
{
	MyCustomThread* th = (MyCustomThread*)thread;
	th->run();
	return 0;
}

void MyCustomThread::run()
{
	for(int i = 0; i < 5; i++)
		std::cout<<getThreadName().c_str()<<" "<<(i + 1)<<std::endl;
}
