#include "threading.h"

using namespace ThreadNameSpace;

const short CThread::P_NORMAL = THREAD_PRIORITY_NORMAL;

CThread::CThread(CMutex* pMutex) :
m_pCMutex(pMutex), m_FileParser(m_pCMutex)
{
}

CThread::~CThread()
{
}

void CThread::CreateNewThread(char* pThreadName, short priority)
{
	DWORD dThreadID;

	setThreadName(pThreadName);

	m_hThreadHandle = CreateThread(NULL, 0, LPTHREAD_START_ROUTINE(threadStartRoutine), this, FALSE, &dThreadID);

	if (m_hThreadHandle == NULL)
	{
		throw CThreadException("Thread Creation failed");
	}
	setPriority(priority);
}

void CThread::setThreadName(char* pThreadName)
{
	m_cpThreadName = pThreadName;
}

char* CThread::getThreadName()
{
	return m_cpThreadName;
}

void CThread::setPriority(short priority)
{
	::SetThreadPriority(m_hThreadHandle, priority);
}

void CThread::run()
{
	try
	{
		m_FileParser.writeToFile(getThreadName(), getThreadName());
	}
	catch(const CFileException& crFileException)
	{
		std::cout << crFileException.what();
	}
}

void ThreadNameSpace::threadStartRoutine(void* param)
{
	CThread* opCThread = static_cast<CThread*>(param);
	opCThread->run();
}