#include <iostream>
#include "User.h"

enum choice
{
	NO_SELECTION,
	TAKE_TEST,
	TEST_STRUCTURE,
	GUIDELINES,
	EXIT
};
class UserInterface
{
	public:
		void init();
		void userSelection(unsigned short);
};