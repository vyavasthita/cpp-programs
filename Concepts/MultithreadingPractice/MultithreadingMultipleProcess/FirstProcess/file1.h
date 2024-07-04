#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;


class First
{
	public:
		First(const char* name);
		void CreateMyMutex();
		HANDLE getMutexHandle();
		void runApp();

private:
	const char* m_pcMutexName;
	HANDLE m_hMutexHandle;
};