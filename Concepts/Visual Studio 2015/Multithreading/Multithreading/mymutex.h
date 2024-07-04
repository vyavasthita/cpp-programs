#pragma once

#include <iostream>
#include <Windows.h>

class MyMutex
{
public:
	~MyMutex();
	MyMutex();

	void CreateNewMutex(const char* mutexName = NULL);

public:
	HANDLE m_hMutexHandle;
	const char* m_constMutexName;
};
