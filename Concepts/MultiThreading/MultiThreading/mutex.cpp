#include "mutex.h"
#include <Windows.h>
#include "thread_exception.h"

Mutex::Mutex() : m_MutexName(""), m_hMutex(NULL)
{
}

Mutex::Mutex(const char* mutexName) : m_MutexName(mutexName), m_hMutex(NULL)
{
	m_hMutex = (unsigned long*)CreateMutex(NULL, FALSE, m_MutexName);

	if(m_hMutex == NULL) 
	{
		throw ThreadException("Failed to create mutex");
	}
}

Mutex::~Mutex()
{
}

const char* Mutex::getMutexName()
{
	return m_MutexName;
}

unsigned long* Mutex::getMutexHandle()
{
	return m_hMutex;
}

void Mutex::create(const char* mutexName)
{
	if(m_hMutex != NULL)
	{
		CloseHandle(m_hMutex);

		m_hMutex = NULL;
	}

	m_MutexName = mutexName;

	m_hMutex = (unsigned long*)CreateMutex(NULL, FALSE, m_MutexName);

	if(m_hMutex == NULL) 
	{
		throw ThreadException("Failed to create mutex");
	}
}

void Mutex::release()
{
	if(m_hMutex != NULL)
	{
		CloseHandle(m_hMutex);

		m_hMutex = NULL;
	}
}