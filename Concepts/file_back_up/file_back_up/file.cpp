#include <fstream>
#include <iostream>
#include<conio.h>
#include <Windows.h>

using namespace std;

void backup(const char* source, const char* dest)
{
	BOOL isExist = TRUE;
	
	int result = CopyFile(source, dest, false);

	if(result == FALSE)
	{
		if(GetLastError() == ERROR_FILE_NOT_FOUND)
		{
			cout<<"source file does not exist\n";
		}
	}
	else
	{
		cout<<"back up successfull\n";
	}
}
void main()
{
	const char* s = "F:\\BU.csv";
	const char* d = "F:\\Back Up\\copy.csv";

	backup(s, d);
	getch();
}
