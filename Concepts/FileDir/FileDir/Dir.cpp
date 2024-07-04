//#include <Shlwapi.h>
//#include <iostream>
//#include <conio.h>
//
//using namespace std;
//#pragma comment(lib, "shlwapi.lib")
//
//void main()
//{
//	if( PathFileExists("F:\\File\\firsst.txt")) 
//	{ 
//		cout<<"Exists\n";
//	} 
//	else
//	{
//		cout<<"Does not Exist\n";
//	}
//	getch();
//}


#include <Windows.h>
#include <iostream>

using namespace std;

bool exists(char* filePath)
{
	//This will get the file attributes bitlist of the file
	DWORD fileAtt = GetFileAttributesA(filePath);

	//If an error occurred it will equal to INVALID_FILE_ATTRIBUTES
	if(fileAtt == INVALID_FILE_ATTRIBUTES)
		//So lets throw an exception when an error has occurred
		throw GetLastError();

	//If the path referers to a directory it should also not exists.
	return ( ( fileAtt & FILE_ATTRIBUTE_DIRECTORY ) == 0 ); 
}

int main()
{
	if (exists("F:\\File\\firsst.txt"))
		cout << "Exists!\n";
	else
		cout << "does not exist!\n";

	return 0;
}