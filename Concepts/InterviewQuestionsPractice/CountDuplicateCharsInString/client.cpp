#include "file.h"
#include <conio.h>

using namespace NamespaceCountChar;
using namespace std;


int main()
{
	const char* input = "abdbaccdbac";

	CountChar countChar;

	while (*input)
	{
		countChar.insertCharInfo(*input++);
	}

	countChar.fetchCharCount();

	_getch();
	return 0;
}