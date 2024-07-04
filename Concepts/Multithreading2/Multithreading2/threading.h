#include <iostream>
#include <Windows.h>
#include "mutex.h"

#ifndef __THREADING_H_
#define __THREADING_H_

namespace MyThread
{
	class Thread
	{
		public:
			Thread();
			Thread(Mutex* pMutex, const char* const_cpThreadName);
		
			~Thread();

			void setThreadName(const char* const_cpThreadName);
			const char* getThreadName();

			void CreateNewThread(char* cpContent = NULL);
			void setPriority(const short int priority);
			void ready();
			void start();
			void suspend();
			void release();
			void stop();

			void writeToFile(const char* const_cpContent);

		private:
			const char* m_const_cpThreadName;

			char* m_cpContent;

			Mutex* m_pMutex;

			static const short int NORMAL;
			static const short int HIGHEST;
			static const short int LOWEST;
			static const short int ABOVE_NORMAL;
			static const short int BELOW_NORMAL;
			static const short int TIME_CRITICAL;

			HANDLE m_hThreadHandle;

			//static void (Thread::*threadRoutine)();
	};
};
#endif __THREADING_H_