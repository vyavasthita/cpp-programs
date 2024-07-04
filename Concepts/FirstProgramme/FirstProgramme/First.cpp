//My First C++ Programme

//this is a single line comment
#include <iostream>
#include <conio.h>

using namespace std;

/*
	This is a multi line comment
*/

int main(int argc, char *arr[])
{
	int iValue = 0;
	cout<<"Enter A Number : "<<endl;
	cin>>iValue;

	cout<<"You have entered : "<<iValue;

	cout<<"Command LIne Argument is : "<<arr[0]<<endl;
	getch();

	return 0;
}