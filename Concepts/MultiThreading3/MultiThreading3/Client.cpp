#include <iostream>
#include <conio.h>
#include "Data.h"
#include "Thread.h"
#include "MyMutex.h"

int main()
{
	CData oCData;
	CMyMutex oCMyMutex(&oCData);
	
	oCMyMutex.CreateMyMutex("MyMutex");

	CThread thread1(&oCData, &oCMyMutex);
	CThread thread2(&oCData, &oCMyMutex);

	thread1.CreateNewThread("One", 10);
	thread2.CreateNewThread("Two", 10);

	getch();
	return 1;
}