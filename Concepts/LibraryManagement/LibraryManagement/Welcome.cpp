#include "Welcome.h"
#include "Login.h"
#include"Book.h"
#include "ClearScreen.h"

void main()
{
	Welcome welcomeObj;
	welcomeObj.welcomeScreen();
	
	getch();
}
void Welcome::welcomeScreen()
{
	unsigned int uiChoice;
	Login loginObj;
	Clear clearObj;

	std::cout<<"*****Welcome to Student Library System******"<<std::endl;
	std::cout<<"\nEnter Your Choice"<<std::endl;
	std::cout<<"1. Sign In"<<std::endl;
	std::cout<<"2. Sign Up"<<std::endl;
	std::cout<<"3. Exit"<<std::endl;
	
	std::cin>>uiChoice;
	clearObj.clearScreen();
	loginObj.userInput(uiChoice);
}



