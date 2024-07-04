#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <conio.h>


using namespace std;

void validatePath(const string& filepath)
{
	string filePath = filepath;
	string directory = filePath.substr(0, (filePath.find_last_of("\\") + 1));
	string searchPattern = "*.pdf";
	string filename = filePath.erase(0, (filePath.find_last_of("\\")) + 1);

	string fullSearchPath = directory + searchPattern;

	WIN32_FIND_DATA FindData;
	HANDLE hFind;
	hFind = FindFirstFile( fullSearchPath.c_str(), &FindData );

	if( hFind == INVALID_HANDLE_VALUE )
	{       
		cout << "Error searching directory\n";
		//return;
	}

	do
	{
		string filePath = directory + FindData.cFileName;

		cout << FindData.cFileName << "\n";
	}
	while( FindNextFile(hFind, &FindData) > 0 );

	if( GetLastError() != ERROR_NO_MORE_FILES )
	{
		cout << "Something went wrong during searching\n";
	}
}
void main()
{
	string path = "C:\\Raja\\Personal data\\Incentive_oct2012.pdf";
	validatePath(path);

	getch();
}

