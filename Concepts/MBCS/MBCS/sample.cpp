#include <iostream>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <Windows.h>


using namespace std;

void main()
{
	/*char *filename = "C:\\C++Practice\\MBCS\\GPDM.csv";
	
	ifstream wif(filename);
	string ws;
	
	getline(wif, ws);

	char* out;*/

	//MultiByteToWideChar(CP_ACP, MB_COMPOSITE, ws.c_str(), ws.size(), NULL, 0);

	ifstream myFS;
    myFS.open("C:\\C++Practice\\MBCS\\GPDM.csv", ios::in);
    string myString; 
    if(myFS.is_open()){
        while(myFS >> myString)
            cout << myString << endl;
    }
    myFS.close();
	
	getch();
}