#pragma once
#include <Windows.h>
#include <iostream>
#include "file.h"

using namespace std;

class MyEvent
{
	public:
		MyEvent(const char* name);
		void CreateMyEvent();
		void setMyEvent();
		HANDLE getEventHandle();

	private:
		const char* m_pcEventName;
		HANDLE m_hEventHandle;
};


class MyMutex
{
	public:
		MyMutex(char* mutexName=NULL);
		void createNewMutex();
		HANDLE getMutexHandle();

	private:
		char* m_pcMutexName;
		HANDLE m_hMutexHandle;		
};

class Mythread
{
	public:
		Mythread(MyMutex* pMutex, MyFile* m_pFile, MyEvent* MyEvent, char* threadName, int count);
		void createNewThread(int priority);
		void threadStartRoutine();
		void resumeMyThread();

		void setMythreadPriority(int priority);
		int getMythreadPriority();

	private:
		MyMutex* m_pMutex;
		MyEvent* m_pMyEvent;
		MyFile* m_pFile;

		char* m_pcThreadName;
		HANDLE m_hThreadHandle;
		int m_nThreadCount;

	public:
		static int PRIORITY_NORMAL;
		static int PRIORITY_LOW;
		static int PRIORITY_HIGH;
};


