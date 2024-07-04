#include "mutex.h"
#include "ThreadException.h"

using namespace MyThread;


Mutex::Mutex()
{
}

Mutex::Mutex(const char* const_pcMutexName) : m_const_cpMutexName(const_pcMutexName)
{
}

Mutex::~Mutex()
{
}

void Mutex::CreateNewMutex()
{
	const char* const_pcMutexName = getMutexName();

	m_hMutexHandle = CreateMutex(NULL, FALSE, const_pcMutexName);

	if(m_hMutexHandle == NULL) 
	{
		throw ThreadException("Failed to create mutex");
	}
}

void Mutex::setMutexName(const char* const_pcMutexName)
{
	m_const_cpMutexName = const_pcMutexName;
}

const char* Mutex::getMutexName()
{
	return m_const_cpMutexName;
}

void Mutex::lockMutex()
{
	if (m_hMutexHandle == NULL)
	{
		return;
	}
	WaitForSingleObject(m_hMutexHandle, INFINITE);
}

void Mutex::release()
{
	if (m_hMutexHandle == NULL)
	{
		return;
	}
	
	ReleaseMutex(m_hMutexHandle);
}

bool Mutex::wait(long waitTime)
{
	m_const_cpMutexName;
	HANDLE h;
	DWORD d;

	h = OpenMutex(MUTANT_ALL_ACCESS, FALSE, m_const_cpMutexName);

	if(h == NULL) 
	{
		throw ThreadException("Mutex not found");
	}

	d = WaitForSingleObject(m_hMutexHandle, INFINITE);

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
