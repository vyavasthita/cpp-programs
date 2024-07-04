#pragma once

#include <iostream>
#include <Windows.h>

class MyEvent
{
	public:
		MyEvent();
		~MyEvent();

		void CreateMyNewEvent(const char* eventName = NULL);

	public:
		HANDLE m_hEventHandle;
		const char* m_constEventName;
};
