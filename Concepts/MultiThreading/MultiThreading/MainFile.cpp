#include "thread_exception.h"
#include "threading.h"
#include <conio.h>

class ChildThread : public Thread
{
	public:
		ChildThread();
		ChildThread(const char* threadName, int count);
		~ChildThread();

	private:
		int m_nCount;
};

ChildThread::ChildThread()
{
}

ChildThread::ChildThread(const char* threadName, int count)
{
}

ChildThread::~ChildThread()
{
}

void main()
{
	Thread* thread1 = new Thread("Thread 1", 5);
	Thread* thread2 = new Thread("Thread 2", 8);

	try
	{
		thread1->CreateNewThread();
		thread2->CreateNewThread();
		thread1->stop();
		thread2->stop();
	}
	catch(const ThreadException& exc)
	{
		std::cout << exc.getErrorMsg() << std::endl;
	}
	getch();
}