/*
Main thread will write to file, till then child threads will wait.
After that all child thread will write to file, based on priority assigned
to them and iteration allocated to them.
*/

#include "threads.h"
#include <conio.h>

int main()
{
	MyFile oFile;
	MyMutex m("mango");
	m.createNewMutex();

	MyEvent oEvent("apple");
	oEvent.CreateMyEvent();

	Mythread th1(&m, &oFile, &oEvent, "Kannu", 5);
	th1.createNewThread(Mythread::PRIORITY_LOW);

	Mythread th2(&m, &oFile, &oEvent, "Raja", 4);
	th2.createNewThread(Mythread::PRIORITY_HIGH);

	Mythread th3(&m, &oFile, &oEvent, "Goolu", 3);
	th3.createNewThread(Mythread::PRIORITY_NORMAL);

	th1.resumeMyThread();
	th3.resumeMyThread();
	th2.resumeMyThread();

	oFile.writeToFile("Main", 1);
	Sleep(5000);
	oFile.writeToFile("Main", 4);

	oEvent.setMyEvent();

	

	_getch();
	return 0;
}