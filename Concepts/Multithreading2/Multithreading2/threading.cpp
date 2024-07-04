#include "threading.h"
#include "ThreadException.h"
#include "file_parser.h"

using namespace MyThread;

const short int MyThread::Thread::NORMAL= THREAD_PRIORITY_NORMAL;
const short int MyThread::Thread::HIGHEST = THREAD_PRIORITY_HIGHEST;
const short int MyThread::Thread::LOWEST = THREAD_PRIORITY_LOWEST;
const short int MyThread::Thread::ABOVE_NORMAL = THREAD_PRIORITY_ABOVE_NORMAL;
const short int MyThread::Thread::BELOW_NORMAL = THREAD_PRIORITY_BELOW_NORMAL;
const short int MyThread::Thread::TIME_CRITICAL = THREAD_PRIORITY_TIME_CRITICAL;

//void (Thread::*threadRoutine)() = &Thread::start;

extern "C"
{
	void ThreadStartRoutine(void *classPtr);
}

Thread::Thread() : m_const_cpThreadName("")
{
}

Thread::Thread(Mutex* pMutex, const char* const_cpThreadName) : m_pMutex(pMutex), m_const_cpThreadName(const_cpThreadName)
{
	
}

Thread::~Thread()
{
}

void Thread::setThreadName(const char* const_cpThreadName)
{
	m_const_cpThreadName = const_cpThreadName;
}

const char* Thread::getThreadName()
{
	return m_const_cpThreadName;
}

void Thread::CreateNewThread(char* cpContent)
{
	m_cpContent = cpContent;

	DWORD dThreadID;

	char* cpErrorMsg = NULL;

	m_hThreadHandle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadStartRoutine, this, 0, &dThreadID);

	if (m_hThreadHandle == NULL)
	{
		cpErrorMsg = "Thread can not be created.";

		throw ThreadException(cpErrorMsg);
	}
	setPriority(NORMAL);
}

void Thread::setPriority(const short int priority)
{
	if (m_hThreadHandle == NULL)
	{
		throw ThreadException("Unable to set priority. Invalid thread.");
	}
	::SetThreadPriority(m_hThreadHandle, priority);
}	

void Thread::start()
{
	bool bStatus = false;

	/*bStatus = m_pMutex->wait();

	if (bStatus == true)
	{*/
		m_pMutex->lockMutex();
		writeToFile(m_cpContent);
		m_pMutex->release();
	//}
}

void Thread::stop()
{
	if (m_hThreadHandle == NULL)
	{
		return;
	}

	WaitForSingleObject(m_hThreadHandle, INFINITE);
	CloseHandle(m_hThreadHandle);
	m_hThreadHandle = NULL;

	std::cout << "Thread " << getThreadName() << " " << "stopped." << std::endl;
}

void Thread::writeToFile(const char* const_cpContent)
{
	const char* const_threadName = getThreadName();

	FileParser::getInstance().WriteToFile(const_threadName, const_cpContent);
}

void ThreadStartRoutine(void *classPtr)
{
	Thread* poThread = (Thread*) classPtr;

	poThread->start();
}