#include "String.h"
#include <conio.h>

using namespace MyCustomString;

void main()
{
	//MyString
	//std::string
	MyString str1 = "hellohi";
	MyString str2;
	str2 = str1.substr(5, 2);

	std::cout<<str2;
	getch();
}