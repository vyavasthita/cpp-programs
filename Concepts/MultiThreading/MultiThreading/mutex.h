#include <iostream>

class Mutex
{
	public:
		Mutex();
		Mutex(const char* mutexName);
		~Mutex();

		void create(const char* mutexName);

		unsigned long* getMutexHandle();

		const char* getMutexName();

		void release();

	private:
		const char* m_MutexName;

		unsigned long* m_hMutex;
};