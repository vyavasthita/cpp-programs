#include <iostream>

class Thread
{
	public:
		Thread();

		Thread(const char* cpThreadName, int count);
		
		virtual ~Thread();

		void setThreadName(const char* cpThreadName);

		const char* getThreadName() const;

		void CreateNewThread();

		void setPriority(short priority);

		void start();

		void run();

		void stop();

		void sleep();

		void suspend();

		void resume();

		bool wait(const char* m, long ms);

	private:
		static const short P_NORMAL;

		const char* m_const_cThreadName;

		unsigned long* m_hThread;

		int m_nCount;
};

extern "C" 
{
	unsigned int threadBeginning(void* param);
}