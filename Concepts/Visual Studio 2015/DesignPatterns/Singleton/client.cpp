#include "logger.h"
#include <conio.h>


int main()
{
	Logger::getInstance()->Log("First");
	Logger::getInstance()->Log("Second");
	_getch();
	return 0;
}