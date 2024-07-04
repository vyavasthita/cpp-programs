#pragma once
#include <iostream>
#include <Windows.h>
#include "file1.h"

using namespace std;


class Second
{
	public:
		Second(const char* name);
		void runApp();

	private:
		const char* m_pcMutexName;
		HANDLE m_hMutexHandle;
};