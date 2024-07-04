#include <Windows.h>
#include <iostream>
#include <conio.h>


void main()
{
	typedef int (*addFunPointer)(int, int);

	HINSTANCE hDLL = LoadLibrary("C:\\C++ Practice 2014\\dynamicDLL.dll");

	if (hDLL == NULL)
	{
		std::cout << "Unable to load the DLL\n";
	}
	else
	{
		std::cout << "DLL loaded successfully\n";
	}

	addFunPointer p = (addFunPointer)GetProcAddress(hDLL, "addNum");

	if (p)
	{
		std::cout << p(5, 7);
	}
	else
	{
		std::cout << "Unable to load DLL function\n";
	}

	FreeLibrary(hDLL);
	getch();
}
