#include "threading.h"
#include "ThreadException.h"
#include "mutex.h"
#include <iostream>
#include <conio.h>

using namespace MyThread;

void main()
{
	Mutex m("my");
	m.CreateNewMutex();

	Thread ob1(&m, "X");
	Thread ob2(&m, "Y");
	Thread ob3(&m, "Z");

	try
	{
		ob1.CreateNewThread("111");

		ob2.CreateNewThread("222");

		ob3.CreateNewThread("333");

		ob1.stop();
		ob2.stop();
		ob3.stop();
	}
	catch(const ThreadException& constrErrorMsg)
	{
		std::cout << "Exception Occurred " << constrErrorMsg.what() << std::endl;
	}
	getch();
}