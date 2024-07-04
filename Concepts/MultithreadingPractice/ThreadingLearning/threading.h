#include <iostream>
#include <Windows.h>
#include "mutex.h"
#include "myexception.h"
#include "fileparser.h"

#ifndef __MY_THREAD_H_
#define __MY_THREAD_H_

namespace ThreadNameSpace
{
	class CThread
	{
		public:
			CThread(CMutex* pMutex);
			~CThread();

			void CreateNewThread(char* pThreadName, short priority);
			void run();

			void setThreadName(char* pThreadName);
			char* getThreadName();

			void setPriority(short priority);

		private:
			CMutex* m_pCMutex;
			CFileParser m_FileParser;

			char* m_cpThreadName;
			HANDLE m_hThreadHandle;

		public:
			static short m_priority;
			static const short P_NORMAL;			
	};

	extern "C"
	{

		void threadStartRoutine(void* param);
	}
};

#endif __MY_THREAD_H_ 