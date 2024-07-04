#pragma once
#include <iostream>
#include "myevent.h"


class MyThread
{
	public:
		MyThread(const MyEvent* pcEvent);
		~MyThread();
		void CreateNewThread(const char* name, int count);

		void threadStartFunction();

		void writeToFile();

	public:
		HANDLE m_hThreadHandle;

		const char* m_FilePath;

		int m_nThreadCount;
		const char* m_constThreadName;

		const MyEvent* m_pcEvent;
};
