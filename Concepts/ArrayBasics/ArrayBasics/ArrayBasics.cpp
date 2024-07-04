//#include<iostream>
//#include<conio.h>
//#include<string>
//
//#define END '\0'
//
//using namespace std;
//void printArray(void *ptr)
//{
//	char * ch;
//	ch = (char*)ptr;
//	while(*ch != END)
//	{
//		cout<<*ch++<<" ";
//	}
//}
//void main()
//{
//	char arr[] = "1234";
//	printArray(arr);
//	getch();
//}

#include<iostream>
#include<conio.h>
#include<string>

void fun(char* p)
{
	std::cout << p[3] << std::endl;
}

void main()
{
	char* p1 = "abcd";
	char* p2 = "efgh";

	char** pp1 = &p1;
	char** pp2 = &p2;

	char*** ppp1 = &pp1;
	char*** ppp2 = &pp2;

	char*** arr[] = {ppp1, ppp2};

	fun(arr[0][0][0]);
	fun(arr[1][0][0]);

	getch();
}