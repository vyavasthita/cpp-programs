//#include <iostream>
//#include <conio.h>
//#include <exception>
//
//using namespace std;
//
//void meth()
//{
//	try
//	{
//		int * myarray= new int[100];
//	}
//	catch (bad_alloc&)
//	{
//	cout << "Error allocating memory." << endl;
//	}
//}
//
//void main()
//{
//	meth();
//	getch();
//}

#include <iostream>
#include <conio.h>
#include <exception>
#include <string>

class CMyException
{
	public:
		void ClassFun()
		{
			strString = "exception has occured\n";
		}
		std::string strString;
};

void fun(int i)
{
	CMyException oCMyException;

	if (i == 0)
	{
		throw oCMyException;
	}
}
void main()
{
	try
	{
		fun(0);
	}
	catch(const CMyException& ooCMyException)
	{
		std::cout << "Exception : value is " << ooCMyException.strString << std::endl;
	}
	getch();
}