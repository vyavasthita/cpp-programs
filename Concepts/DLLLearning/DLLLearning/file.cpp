#include "file.h"
#include "MyDLL.h"


typedef int (MyDLLClass::*FNPTR)(int, int);

CLearning::CLearning(const char* cpDLLPath) : m_cpDLLPath(cpDLLPath)
{
}

CLearning::~CLearning()
{
	FreeMyDLL();
}

void CLearning::LoadMyDLL()
{
	m_DLLHandle = LoadLibrary(m_cpDLLPath);

	if (m_DLLHandle)
	{
		cout << "DLL Loaded successfully.\n";
	}
	else
	{
		throw("DLL could not be loaded.\n");
	}
}

void CLearning::FreeMyDLL()
{
	BOOL result;

	result = FreeLibrary(m_DLLHandle);

	if (result == 0 )
	{
		cout << "DLL Could not be Unloaded.\n";
	}
	else
	{
		cout << "DLL Unloaded successfully\n";
	}
}

int CLearning::Add(int a, int b)
{
	FNPTR ptr = (FNPTR)GetProcAddress(m_DLLHandle, "MyDLLClass::AddNumber");

	if (ptr == NULL)
	{
		throw("Function not found in DLL.\n");
	}

	int result = ptr(a, b);
	return result;
}