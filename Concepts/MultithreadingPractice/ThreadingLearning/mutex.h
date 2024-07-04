#include <iostream>
#include <Windows.h>
#include "myexception.h"


#ifndef __MY_MUTEX_H_
#define __MY_MUTEX_H_

namespace ThreadNameSpace
{
	class CMutex
	{
		public:
			CMutex();
			CMutex(const char* cpMutexName);
			~CMutex();

			void CreateNewMutex();

			bool wait();

		private:
			HANDLE m_hMutexHandle;
		public:
			const char* m_const_cpMutexName;
			
	};
};

#endif __MY_MUTEX_H_ 