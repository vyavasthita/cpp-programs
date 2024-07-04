//#include <iostream>
//#include <conio.h>
//
//using namespace std;
//
//class MyClass
//{
//	int iVar;
//
//	MyClass()
//	{
//		iVar = 5;
//	}
//
//	friend void fun();
//};
//
//void fun()
//{
//	MyClass tempObj;
//	cout <<" iVar is : "<<tempObj.iVar<<endl;
//}
//
//void main()
//{
//	fun();
//	getch();
//}

#include <iostream>
#include <conio.h>

using namespace std;

class FriendClass
{
	public:
		void friendfun()
		{
		}
};

class MyClass
{
	int iVar;

	MyClass()
	{
		iVar = 5;
	}

	friend void fun();
	friend void FriendClass::friendfun();
};



void fun()
{
	MyClass tempObj;
	cout <<" iVar is : "<<tempObj.iVar<<endl;
}

void main()
{
	fun();
	getch();
}