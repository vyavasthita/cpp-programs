#include <iostream>
#include <conio.h>
#include "Welcome.h"
#include "Login.h"

using namespace LMS;

void WelCome::Welcome()
{
	Login logObj;
}
void WelCome::welcomeScreen()
{
	std::cout<<"*********Welcome************"<<std::endl;
	std::cout<<"Press 1 to Sign In or Press 2 to Sign Up or 3 to exit : ";

	std::cin>>choice;
	clearScreen();
	selectedChoice(choice);
}
void WelCome::selectedChoice(unsigned int choice)
{
	switch(choice)
	{
		case SIGN_IN:
			{
				userName();
				password();
				proceed();
				break;
			}
		case SIGN_UP:
			{
				userName();
				password();
				signUpUser(userInfo.name, userInfo.password);
				break;
			}
		case EXIT:
			break;
		default:
			{
				break;
			}
	}
}
void WelCome::userName()
{
	std::cout<<"Enter User Name : ";
	std::cin>>userInfo.name;
	std::cout<<std::endl;
}
void WelCome::password()
{
	std::cout<<"Enter Password : ";
	std::cin>>userInfo.password;
	std::cout<<std::endl;
}
void WelCome::proceed()
{
	Login logObj;
	bool result;
	result = logObj.validateCredential(userInfo.name, userInfo.password);

	if(result)
	{
		std::cout<<"Success"<<std::endl;
	}
	else
	{
		std::cout<<"Wrong Credential"<<std::endl;
		welcomeScreen();
	}
}
void WelCome::signUpUser(std::string  name, std::string pass)
{
	bool res = false;
	Login logObj;
	res = logObj.addUserName(name);

	if(res)
	{
		std::cout<<"User already exists";
	}
	else
	{
		std::cout<<"User added successfully";
	}
	welcomeScreen();
}
void main()
{
	WelCome welObj;
	welObj.welcomeScreen();
	getch();
}