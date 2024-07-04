#pragma once

#include <iostream>
#include <Windows.h>

class MyCS
{
public:
	~MyCS();
	MyCS();

	void InitializeCS();

public:
	HANDLE m_hMutexHandle;
	CRITICAL_SECTION m_cs;
};
