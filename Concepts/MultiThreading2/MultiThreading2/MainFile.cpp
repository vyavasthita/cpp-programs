#include "multithreading.h"
#include <conio.h>


void main()
{
	MyCustomThread* thread1 = new MyCustomThread;
	MyCustomThread* thread2 = new MyCustomThread;

	thread1->setThreadName("Thread X");
	thread2->setThreadName("Thread Y");

	try
	{
		thread1->start();
		thread2->start();
		thread1->stop();
		thread2->stop();
	}
	catch(ThreadException ex) 
	{
		std::cout<<ex.getMessage().c_str();
	}

	delete thread1;
	delete thread2;

	getch();
}