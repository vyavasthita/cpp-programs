#include <iostream>
#include "Data.h"
#include "MyMutex.h"

class CThread
{
	public:
		CThread(void);
		CThread(CData* poCData, CMyMutex* poCMyMutex);
		virtual ~CThread(void);

		void CreateNewThread(const char* cpThreadName, short time);

		void setPriority();
		void printData();

	protected:
		CData* m_poCData;
		CMyMutex* m_poCMyMutex;

		const char* m_pcThreadName;
		short int m_nTime;
};

