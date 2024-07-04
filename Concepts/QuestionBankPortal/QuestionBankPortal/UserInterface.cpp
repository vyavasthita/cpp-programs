#include <iostream>
#include <conio.h>
#include "UserInterface.h"

using namespace std;
using namespace Exams;

void UserInterface::init()
{
	unsigned short usSelection = 0;

	cout<<"Welecome to Question Bank Portal\n---------------------------------------------\n";
	cout<<"1. Take Test\n";
	cout<<"2. Test Structure\n";
	cout<<"3. Test Guidelines\n";
	cout<<"4. Exit\n";
	cin>>usSelection;
}

void UserInterface::userSelection(unsigned short selection)
{
	switch(selection)
	{
		case TAKE_TEST:
			break;
		case TEST_STRUCTURE:
			break;
		case GUIDELINES:
			break;
		case EXIT:
			break;
	}
}

void main()
{
	UserInterface object;
	object.init();
	getch();
}