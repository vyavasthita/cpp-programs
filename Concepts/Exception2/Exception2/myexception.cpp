#include "myexception.h"

#include <conio.h>

MyException::MyException()
{
}

MyException::MyException(const char *const_pcErrorMsg) : m_const_pcErrorMessage(const_pcErrorMsg)
{
}

MyException::~MyException() throw
{
}

void MyException::expFunction()
{
	char * msg = "This is an error msg";

	throw MyException(msg);
}

const char* MyException::what() const throw()
{
	return m_const_pcErrorMessage;
}

int main()
{
	MyException ob;

	try
	{
		ob.expFunction();
	}
	catch (MyException ob)
	{
		std::cout << "Exception Occurred --> " << ob.what() << std::endl;
	}

	getch();
	return 1;
}