#include "MyMutex.h"


CMyMutex::CMyMutex(void) : m_pcMutexName("")
{
}

CMyMutex::CMyMutex(CData* poCData) : m_poCData(poCData), m_pcMutexName("")
{
}

CMyMutex::~CMyMutex(void)
{
}

void CMyMutex::CreateMyMutex(const char* cpMutexName)
{
	m_pcMutexName = cpMutexName;

	m_hMutexHandle = CreateMutex(NULL, FALSE, m_pcMutexName);
}

void CMyMutex::printData(const char* cpThreadName, short int time)
{
	DWORD dwWaitResult;

	dwWaitResult = WaitForSingleObject(m_hMutexHandle, INFINITE);

	switch (dwWaitResult) 
        {
            // The thread got ownership of the mutex
            case WAIT_OBJECT_0: 
				for(short int i = 0; i < time; i++)
				{
					m_poCData->printData(cpThreadName);
				}
				
				ReleaseMutex(m_hMutexHandle);

			case WAIT_ABANDONED:
				break;
		}
}