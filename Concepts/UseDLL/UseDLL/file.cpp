#include "file.h"
#include <Windows.h>

void UseDLL::addNum(int a, int b)
{
	HMODULE h = NULL;

	const char* path = "C:\\Raja\\TechnicalStudy\\Source_Code\\CPP_Source_Code\\CreateMyDLL\\Release\\CreateMyDLL.dll";

	h = LoadLibrary(TEXT(path));

	if (h == NULL)
	{
		cout << "Library NOT loaded\n";
	}
	else
	{
		cout << "Library Successfully loaded\n";
	}

	typedef int(*pICFUNC) (int, int);  

	pICFUNC fptr = (pICFUNC)GetProcAddress(h, "addNum");
	
	if (fptr == NULL)
	{
		cout << "Function NOT loaded\n";
	}
	else
	{
		cout << "Function Successfully loaded\n";
	}

	FreeLibrary(h);
}