#include "String.h"
#include <conio.h>

using namespace MyCustomString;

void main()
{
	//MyString
	//std::string
	std::string str2 = "hi";
	std::string str1 = "hello";
	str1.insert(2, str2);
	std::cout<<str1.c_str();
	getch();
}