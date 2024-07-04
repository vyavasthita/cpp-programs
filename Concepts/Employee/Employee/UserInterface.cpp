#include <iostream>
#include <conio.h>
#include <string>
#include <stdexcept>
#include "Database.h"

using namespace std;
using namespace Records;

int displayMenu();
void doHire(Database& inDB);
void doFire(Database& inDB);
void doPromote(Database& inDB);
void doDemote(Database& inDB);

void main()
{
	Database employeeDB;
	bool done = false;

	while(!done)
	{
		int selection  = displayMenu();

		switch(selection)
		{
			case 1:
				doHire(employeeDB);
				break;
			case 2:
				doFire(employeeDB);
			case 3:
				doPromote(employeeDB);
				break;
			case 4:
				employeeDB.displayAll();
				break;
			case 5:
				employeeDB.displayCurrent();
				break;
			case 6:
				employeeDB.displayFormer();
				break;
			case 0:
				done = true;
				break;
			default :
				cerr<<"Unknown command"<<endl;
		}
	}
	getch();
}

int displayMenu()
{
	int selection;

	cout<<endl;
	cout<<"Employee Database"<<endl<<"-------------------------"<<endl;
	cout<<"1. Hire a new employee\n";
	cout<<"2. Fire an employee\n";
	cout<<"3. Promote an employee\n";
	cout<<"4. List all employees\n";
	cout<<"5. List all current employees\n";
	cout<<"6. List all formar employees\n";
	cout<<"0. Quit\n";

	cin>>selection;
	return selection;
}

void doHire(Database &inDB)
{
	string firstName, lastName;

	cout<<"First Name ?";
	cin>>firstName;
	cout<<"Last Name";
	cin>>lastName;

	try
	{
		inDB.addEmployee(firstName, lastName);
	}
	catch(std::exception ex)
	{
		cerr<<"Unable to add an employee!\n";
	}
}

void doFire(Database &inDB)
{
	int employeeNumber;

	cout<<"Employee Number ?";
	cin>>employeeNumber;

	try
	{
		Employee& emp = inDB.getEmployee(employeeNumber);
		emp.fire();
		cout<<"Employee "<<employeeNumber<<" has been terminated\n";
	}
	catch(std::exception ex)
	{
		cerr<<"Unable to terminate employee!\n";
	}
}

void doPromote(Database& inDB)
{
	int employeeNumber;
	int raiseAmount;
	cout<<"Employee Number ?";
	cin>>employeeNumber;

	cout<<"How much of a raise ?";
	cin>>raiseAmount;

	try
	{
		Employee& emp = inDB.getEmployee(employeeNumber);
		emp.promote(raiseAmount);
		cout<<"Employee "<<employeeNumber<<" has been promoted\n";
	}
	catch(std::exception ex)
	{
		cerr<<"Unable to promote employee!\n";
	}

}
