#include "login.h"
#include <string>
  
void Person::welcome()
{
	unsigned short usChoice = NO_CHOICE;

	cout<<"1. Login\n";
	cout<<"2. Sign Up\n";
	cout<<"3. Exit\n";

	cin>>usChoice;
	userChoice(usChoice);
}

void Person::userChoice(unsigned short choice)
{
	string strName = "";
	string strPassword = "";
	bool bFlag = false;
	switch(choice)
	{
		case LOGIN:
			{
				cout<<"Enter your user name\n";
				cin>>strName;

				cout<<"Enter your password\n";
				cin>>strPassword;

				bFlag = validatePerson(strName, strPassword);

				
				if(bFlag)
				{
					cout<<"Login Successfully\n";					
				}
				else
				{
					cout<<"Incorrect Username/Password\n";
				}

				object.welcome();
				break;
			}
			
		case SIGN_UP:
			{
				cout<<"Enter your user name\n";
				cin>>strName;

				cout<<"Enter your password\n";
				cin>>strPassword;

				bFlag = addPerson(strName, strPassword);

				if(!bFlag)
				{
					cout<<"User Already Exists, user another user name\n";
				}
				else
				{
					cout<<"User added successfully\n";					  					
				}
				object.welcome();
				break;
			}
			
		case EXIT:
			{
				break;
			}
		default:
			{
				break;
			}
	}
}

bool Person::addPerson(string name, string password)
{
	p = person.insert(pair<string, string>(name, password));
	return p.second;
}

bool Person::validatePerson(string name, string password)
{
	bool bResult = false;

	it = person.begin();
	it = person.find(name);

	if(it != person.end())
	{
		bResult = true;
	}
	return bResult;
}

void main()
{
	object.welcome();
	getch();
}