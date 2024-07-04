#include <iostream>
#include <conio.h>
#include <process.h>
#include <Windows.h>
#include <string>

using namespace std;


class MyThread
{
	public:
		MyThread();
		~MyThread();

		void CreateMyThread(string threadName, int priority);
		void SetThreadName(string strThreadName);
		static string GetThreadName();
		void SetPriority(HANDLE hThread, int Priority);
		static unsigned WINAPI MyThreadFun(void *vptr);
		static void RunThread();
		void StopThread();

	public:
		static string m_strThreadName;
		int m_nThreadNo;
		static HANDLE hMutex;
		static const int P_IDLE_PRIORITY;
		static const int P_LOWEST_PRIORITY;
		static const int P_BELOW_NORMAL_PRIORITY;
		static const int P_NORMAL_PRIORITY;		
		static const int P_ABOVE_NORMAL_PRIORITY;
		static const int P_HIGHEST_PRIORITY;
		static const int P_CRITICAL_PRIORITY;
};