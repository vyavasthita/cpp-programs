#pragma once
#include <iostream>
#include "mycs.h"


class MyThread
{
	public:
		MyThread(MyCS* cpCS);
		~MyThread();
		void CreateNewThread(const char* name, int count);

		void threadStartFunction();

		void writeToFile();

	public:
		HANDLE m_hThreadHandle;

		const char* m_FilePath;

		int m_nThreadCount;
		const char* m_constThreadName;

		MyCS* m_ptrCS;
};
