#include <Windows.h>
#include <iostream>

#ifndef __MUTEX_H_
#define __MUTEX_H_

namespace MyThread
{
	class Mutex
	{
		public:
			Mutex();
			Mutex(const char* const_pcMutexName);
			~Mutex();

			void CreateNewMutex();

			void setMutexName(const char* const_pcMutexName);

			const char* getMutexName();

			void lockMutex();

			void release();

			bool wait(long waitTime = 10);

		private:
			const char* m_const_cpMutexName;
			HANDLE m_hMutexHandle;
	};
};

#endif __MUTEX_H_