#include "myevent.h"
#include <iostream>

using namespace std;


MyEvent::MyEvent()
{

}
MyEvent::~MyEvent()
{
	::CloseHandle(m_hEventHandle);
}

void MyEvent::CreateMyNewEvent(const char* eventName)
{
	m_constEventName = eventName;

	m_hEventHandle = ::CreateEvent(NULL, TRUE, FALSE, m_constEventName);

	if (m_hEventHandle == NULL)
	{
		cout << "Unable to create Event\n";
	}
}

