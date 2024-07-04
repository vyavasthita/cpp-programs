#ifndef __MULT_THRD_H_
#define __MULT_THRD_H_

#include <iostream>
#include <Windows.h>
#include "ThreadExecption.h"

class MyCustomThread
{
	public:
		MyCustomThread();
		~MyCustomThread();
		void setThreadName(std::string strName);
		std::string getThreadName();
		void start();
		void run();
		void sleep(long ms);
		void wait();
		void stop();
		void setPriority(int priority);
		
	private:
		std::string mstrThreadName;
		unsigned long* m_Thread;
		
		// Thread priorities
		static const int P_ABOVE_NORMAL;
		static const int P_BELOW_NORMAL;
		static const int P_HIGHEST;
		static const int P_IDLE;
		static const int P_LOWEST;
		static const int P_NORMAL;
		static const int P_CRITICAL;
};

extern "C"
{
	unsigned int processThread(void* thread);
}
#endif __MULT_THRD_H_