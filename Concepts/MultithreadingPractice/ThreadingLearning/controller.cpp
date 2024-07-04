#include "controller.h"
#include "threading.h"
#include "myexception.h"

using namespace ThreadNameSpace;


CController::CController()
{
}

CController::~CController()
{
}

void CController::Initialize()
{
	CMutex m_oCMutex("mutex1");
	
	try
	{
		m_oCMutex.CreateNewMutex();
	}
	catch(const CThreadException& crThreadException)
	{
		std::cout << crThreadException.what();
	}

	CThread thread1(&m_oCMutex);

	try
	{
		thread1.CreateNewThread("thread1", CThread::P_NORMAL);
	}
	catch(const CThreadException& crThreadException)
	{
		std::cout << crThreadException.what();
	}

	CThread thread2(&m_oCMutex);

	try
	{
		thread2.CreateNewThread("thread2", CThread::P_NORMAL);
	}
	catch(const CThreadException& crThreadException)
	{
		std::cout << crThreadException.what();
	}
}