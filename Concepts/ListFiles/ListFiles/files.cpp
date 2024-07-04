
#include <iostream>
#include <string>
#include <sstream>	
#include <conio.h>


using namespace std;
	  

void main()
{
	char arr[6];

	cin.getline(arr, 6 + 1);
	
	string str(arr);
	cout<<(char*)str.c_str();
	getch();
}
