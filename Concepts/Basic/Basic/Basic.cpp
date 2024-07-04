#include <iostream>
#include<conio.h>
#define LINE '\n'
using namespace std;

void printArray(int*);

void printArray(int* ptr)
{
	cout<<"Here is your array -->"<<LINE;
	cout<<"*****"<<LINE;
	for(unsigned int ui = 0; ui < 2; ui++)
	{
		for(unsigned int uj = 0; uj < 2; uj++)
		{
			cout<<*ptr++<<" ";
		}
		cout<<LINE;
	}
	cout<<"*****";
}
void main()
{
	int arr[2][2];
	int value = 0;
	for(unsigned int ui = 0; ui < 2; ui++)
	{
		cout<<"Fill row "<<(ui + 1)<<LINE;
		for(unsigned int uj = 0; uj < 2; uj++)
		{
			cout<<"Fill column "<<(uj + 1)<<" of "<<"row "<<(ui + 1)<<"-->";
			cin>>arr[ui][uj];
		}
	}
	printArray(arr[0]);
	getch();
	return;
}