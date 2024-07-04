#include <iostream>
#include <conio.h>
#include <fstream>
#include <sstream>



using namespace std;
	

void main()
{
	wchar_t *filename = L"F:\\demo.csv";
	
	wstring temp;

	wifstream fstr;
		
	fstr.open(filename, wifstream::binary);

	if (fstr.fail())
	{
		std::cout<<"File Open Error\n";
	}
	else
	{
		std::cout<<"File Open Success\n";
	}

	wchar_t buffer[100];

	fstr.read (buffer, 3);

	if (buffer[0] == 0XEF && buffer[1] == 0XBB && buffer[2] == 0XBF) 
	{
		//cout<<"UTF-8";
		//getline (fstr, temp);
		//temp.erase(0, 3);
	}
	else
	{
		std::cout<<"Other";
	}

	getline(fstr, temp);

	wcout<<temp.c_str();

	fstr.close();

	ifstream ifs;

	ifs.open(filename);

	string str;
	getline(ifs, str);

	str.erase(0, 3);
	cout<<"\n\n\n\n\n\n\nValue is "<<str.c_str();

 	getch();
}	