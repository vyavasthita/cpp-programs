#include "mythread.h"
#include "mymutex.h"
#include <conio.h>


int main()
{
	MyMutex myMutex;
	myMutex.CreateNewMutex("dummy");

	MyThread thread1(&myMutex);
	MyThread thread2(&myMutex);
	MyThread thread3(&myMutex);
	MyThread thread4(&myMutex);

	thread1.CreateNewThread("Raja", 1);
	thread2.CreateNewThread("Shilpa", 3);
	thread3.CreateNewThread("Kunal", 7);
	thread4.CreateNewThread("Goolu", 4);

	_getch();
	return 0;
}