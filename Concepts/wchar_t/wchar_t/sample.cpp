#include <iostream>
#include <conio.h>
#include <windows.h>
#include <tchar.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;
	
typedef basic_string<TCHAR> tstring;
vector<tstring> vec;

std::string GetWindowsLastErrorMsg()
{
	DWORD dwError = GetLastError();
	if (dwError)
	{
		LPVOID lpMsgBuf;
		DWORD bufLen = FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dwError,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR) &lpMsgBuf,
        0, NULL );
		
		if (bufLen)
		{
		  LPCSTR lpMsgStr = (LPCSTR)lpMsgBuf;
		  std::string result(lpMsgStr, lpMsgStr+bufLen);
      
		  LocalFree(lpMsgBuf);

		  return result;
		}
	}
	return "No Error";
}

void split(tstring str)
{
	typedef basic_istringstream<TCHAR> tistringstream;

	TCHAR ch = _T(',');

	tstring temp = _T("");

	tistringstream sstrStream(str);
	
	while (!sstrStream.eof())
	{
		try
		{
			getline(sstrStream, temp, ch);
			vec.push_back(temp);
		}
		catch (const std::runtime_error& rErr)
		{
			
		}
	}
}

void main()
{
	char *ptr = NULL;
	tstring filepath = _T("I:\\Data\\C++ Learning\\file.txt");
	wchar_t *res = NULL;

	typedef basic_ifstream<TCHAR, char_traits<TCHAR> > tifstream;

	tifstream ws; 

	ws.open(filepath);

	tstring temp = _T("");

	while (ws.good())
	{
		getline(ws, temp);
		MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, temp.c_str(), temp.size(), res, 0);
		cout<<GetWindowsLastErrorMsg();
	}

	getch();
}	