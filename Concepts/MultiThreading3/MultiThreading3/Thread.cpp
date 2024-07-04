#include "Thread.h"
#include <Windows.h>

void ThreadStartRoutine(void* pointer);

CThread::CThread(void) : m_pcThreadName(""), m_nTime(0)
{
}

CThread::CThread(CData* poCData, CMyMutex* poCMyMutex) : 
m_poCData(poCData), m_poCMyMutex(poCMyMutex), 
	m_pcThreadName(""), m_nTime(0)

{
}

CThread::~CThread(void)
{
}

void CThread::CreateNewThread(const char* cpThreadName, short time)
{
	m_pcThreadName = cpThreadName;
	m_nTime = time;
	
	DWORD threadID;
	HANDLE threadHandle;

	threadHandle = CreateThread(NULL, 0, LPTHREAD_START_ROUTINE(ThreadStartRoutine), this, false, &threadID);

	if (threadHandle == NULL)
	{
	}
}

void CThread::printData()
{
	m_poCMyMutex->printData(m_pcThreadName, m_nTime);
}

void ThreadStartRoutine(void* pointer)
{
	CThread* threadPointer = static_cast<CThread*>(pointer);

	threadPointer->printData();
}
