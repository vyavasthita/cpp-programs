#include "practice.h"

const int MyThread::P_IDLE_PRIORITY = THREAD_PRIORITY_IDLE;
const int MyThread::P_LOWEST_PRIORITY = THREAD_PRIORITY_LOWEST;
const int MyThread::P_BELOW_NORMAL_PRIORITY = THREAD_PRIORITY_BELOW_NORMAL;
const int MyThread::P_NORMAL_PRIORITY = THREAD_PRIORITY_NORMAL;
const int MyThread::P_ABOVE_NORMAL_PRIORITY = THREAD_PRIORITY_ABOVE_NORMAL;
const int MyThread::P_HIGHEST_PRIORITY = THREAD_PRIORITY_HIGHEST;
const int MyThread::P_CRITICAL_PRIORITY = THREAD_PRIORITY_TIME_CRITICAL;

string MyThread::m_strThreadName;
HANDLE MyThread::hMutex;

MyThread::MyThread()
{
	
}

MyThread::~MyThread()
{
}

void MyThread::CreateMyThread(string threadName, int priority)
{
	HANDLE hThreadHandle = (HANDLE)_beginthreadex(NULL, 0, MyThreadFun, 0, 0, NULL);
	SetThreadName(threadName);
	SetPriority(hThreadHandle, priority);
}

void MyThread::SetThreadName(string strThreadName)
{
	m_strThreadName = strThreadName;
}

string MyThread::GetThreadName()
{
	return m_strThreadName;
}

void MyThread::SetPriority(HANDLE hThread, int Priority)
{
	BOOL b = SetThreadPriority(hThread, Priority);
}

unsigned WINAPI MyThread::MyThreadFun(void *vptr)
{
	WaitForSingleObject(hMutex, 100);
	RunThread();  
	ReleaseMutex(hMutex);
	return 0;
}

void MyThread::RunThread()
{
	for (int i = 1; i <= 5; i++)
	{
		cout << " Thread " << GetThreadName() << " with value " << i << endl;
	}
}

void MyThread::StopThread()
{
	//WaitForSingleObject();
}

void main()
{
	MyThread ob;

	ob.hMutex = CreateMutex(NULL, true, "MyMutex");

	ob.CreateMyThread("First", ob.P_ABOVE_NORMAL_PRIORITY);
	ob.CreateMyThread("Two", ob.P_HIGHEST_PRIORITY);
	ob.CreateMyThread("Three", ob.P_LOWEST_PRIORITY);
	ob.CreateMyThread("Four", ob.P_BELOW_NORMAL_PRIORITY);
	getch();
}