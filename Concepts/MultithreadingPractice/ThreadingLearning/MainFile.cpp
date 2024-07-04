#include <iostream>
#include <conio.h>
#include "controller.h"
#include <Windows.h>

using namespace ThreadNameSpace;

int main()
{
	CController oCController;

	oCController.Initialize();
	Sleep(10000);
//	getch();
	return 0;
}