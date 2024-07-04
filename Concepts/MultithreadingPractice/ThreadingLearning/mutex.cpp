#include "mutex.h"
#include "myexception.h"

using namespace ThreadNameSpace;

CMutex::CMutex()
{
}

CMutex::CMutex(const char* cpMutexName) :
m_const_cpMutexName(cpMutexName)
{
}

CMutex::~CMutex()
{
}

void CMutex::CreateNewMutex()
{
	m_hMutexHandle = CreateMutex(NULL, FALSE, m_const_cpMutexName);

	if (m_hMutexHandle == NULL)
	{
		throw CThreadException("Unable to create Mutex");
	}
	std::cout << "Mutex " << m_const_cpMutexName << " " << "Created Successfully\n";
}

bool CMutex::wait()
{
	DWORD d;

	HANDLE hMutexHandle = OpenMutex(MUTANT_ALL_ACCESS, FALSE,m_const_cpMutexName);

	if (hMutexHandle == NULL)
	{
		throw CThreadException("Mutex not found");
	}

	d = ::WaitForSingleObject(hMutexHandle, INFINITE);

	switch(d)
	{
		case WAIT_OBJECT_0 :
			return TRUE;
		case WAIT_TIMEOUT :
			return FALSE;
		default :
			return FALSE;
	}
}