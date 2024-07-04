#pragma once
#include "Data.h"
#include <Windows.h>
class CMyMutex
{
	public:
		CMyMutex(void);
		CMyMutex(CData* poCData);
		virtual ~CMyMutex(void);

		void CreateMyMutex(const char* cpMutexName);
		void printData(const char* cpThreadName, short int time);

	protected:
		const char* m_pcMutexName;

		CData* m_poCData;

		HANDLE m_hMutexHandle;
};

