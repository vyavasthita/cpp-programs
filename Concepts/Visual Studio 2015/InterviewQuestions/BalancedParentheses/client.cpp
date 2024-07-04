#include "file.h"
#include <conio.h>


using namespace NAMESPACE_PARENTHESES;


int main()
{
	std::string strInput = "[()]{}{[()()]()}";
	Parentheses ob;

	if (ob.areParenthesesBalanced(strInput))
	{
		std::cout << "YES\n";
	}
	else
	{
		std::cout << "NO\n";
	}

	_getch();
	return 0;
}