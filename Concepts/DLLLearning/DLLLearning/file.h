#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

class CLearning
{
	public:
		CLearning(const char* cpDLLPath);
		~CLearning();

		void LoadMyDLL();
		void FreeMyDLL();
		int Add(int, int);

	private:
		const char* m_cpDLLPath;
		HMODULE m_DLLHandle;
};