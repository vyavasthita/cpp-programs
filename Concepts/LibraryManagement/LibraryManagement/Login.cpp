#include <iostream>
#include <conio.h>
#include "Login.h"
#include "UserData.h"
#include "Book.h"

enum Choice
{
	SIGN_IN = 1,
	SIGN_UP,
	EXIT
};

struct User
{
	char name[10];
	char password[10];
	char reTypePassword;
}userInfo;

void Login::userInput(unsigned int choice)
{
	UserData userDataObj;
	Book bookObj;
	bool bResult = false;
	switch(choice)
	{
		case SIGN_IN:
			{
				bool bResult = false;

				userName();		
				password();
				bResult = userDataObj.validateUser(userInfo.name, userInfo.password);

				if(bResult)
				{					
					bookObj.displayInfo();					
				}
				else
				{
					std::cout<<"Login Failed"<<std::endl;
				}
				break;
			}
		case SIGN_UP:
			 {			
				 userName();		
				 password();
				 bResult = userDataObj.addUser(userInfo.name, userInfo.password);

				 if(bResult)
				 {
					std::cout<<"Added Successfully"<<std::endl;				
				 }
				 else
				 {
					 std::cout<<"User already exists, give another name\n";
				 }
				 break;
			 }
		case EXIT:
			{
				return;
			}
		default:
			{
				std::cout<<"Wrong Choice"<<std::endl;
				break;
			}
	}
}
void Login::userName()
{
	std::cout<<"Enter Your User Name : "<<std::endl;
	std::cin>>userInfo.name;
}
void Login::password()
{
	std::cout<<"Enter Your Password : "<<std::endl;
	std::cin>>userInfo.password;
}