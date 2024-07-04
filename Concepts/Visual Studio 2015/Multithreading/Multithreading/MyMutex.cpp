#include "mymutex.h"
#include <iostream>

using namespace std;


MyMutex::MyMutex()
{

}
MyMutex::~MyMutex()
{

}

void MyMutex::CreateNewMutex(const char* mutexName)
{
	m_constMutexName = mutexName;

	m_hMutexHandle = ::CreateMutex(NULL, FALSE, m_constMutexName);

	if (m_hMutexHandle == NULL)
	{
		cout << "Unable to create Mutex\n";
	}
}

