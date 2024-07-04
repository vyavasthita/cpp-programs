#include "threads.h"


int Mythread::PRIORITY_HIGH = THREAD_PRIORITY_HIGHEST;
int Mythread::PRIORITY_NORMAL = THREAD_PRIORITY_NORMAL;
int Mythread::PRIORITY_LOW = THREAD_PRIORITY_LOWEST;


void ThreadFunc(void* ptr)
{
	Mythread* threadPtr = static_cast<Mythread*>(ptr);
	threadPtr->threadStartRoutine();
}

Mythread::Mythread(MyMutex* pMutex, MyFile* pFile, MyEvent* MyEvent, char* threadName, int count) :
	m_pMutex(pMutex), m_pFile(pFile), m_pMyEvent(MyEvent),
	m_pcThreadName(threadName),
	m_nThreadCount(count)
{

}

void Mythread::createNewThread(int priority)
{
	m_hThreadHandle = CreateThread(NULL, 0, LPTHREAD_START_ROUTINE(ThreadFunc), this, CREATE_SUSPENDED, NULL);

	if (m_hThreadHandle == NULL)
	{
		cout << "Thread " << m_pcThreadName << " creation failed.\n";
	}
}

void Mythread::setMythreadPriority(int priority)
{
	SetThreadPriority(m_hThreadHandle, priority);
}

void Mythread::threadStartRoutine()
{
	HANDLE handleCount[2] = { m_pMutex->getMutexHandle(), m_pMyEvent->getEventHandle() };
	DWORD d = WaitForMultipleObjects(2, handleCount, TRUE, INFINITE);
	
	switch (d)
	{
		case WAIT_OBJECT_0:
			m_pFile->writeToFile(m_pcThreadName, m_nThreadCount);
			ReleaseMutex(m_pMutex->getMutexHandle());
			break;
		default:
			break;
	}
}

void Mythread::resumeMyThread()
{
	ResumeThread(m_hThreadHandle);
}

MyMutex::MyMutex(char* mutexName):
	m_pcMutexName(mutexName)
{

}

void MyMutex::createNewMutex()
{
	m_hMutexHandle = CreateMutex(NULL, FALSE, m_pcMutexName);

	if (m_hMutexHandle == NULL)
	{
		cout << "Mutex creation error\n";
	}
}

HANDLE MyMutex::getMutexHandle()
{
	return m_hMutexHandle;
}

MyEvent::MyEvent(const char* name) :
	m_pcEventName(name)
{

}

void MyEvent::CreateMyEvent()
{
	m_hEventHandle = CreateEvent(NULL, TRUE, FALSE, m_pcEventName);
}

void MyEvent::setMyEvent()
{
	SetEvent(m_hEventHandle);
}

HANDLE MyEvent::getEventHandle()
{
	return m_hEventHandle;
}