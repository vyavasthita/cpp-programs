#include "mythread.h"
#include <conio.h>
#include "mycs.h"


int main()
{
	MyCS cs;
	cs.InitializeCS();

	MyThread thread1(&cs);
	MyThread thread2(&cs);
	MyThread thread3(&cs);
	MyThread thread4(&cs);

	thread1.CreateNewThread("Raja", 11);
	thread2.CreateNewThread("Shilpa", 13);
	thread3.CreateNewThread("Kunal", 70);
	thread4.CreateNewThread("Goolu", 45);

	_getch();
	return 0;
}