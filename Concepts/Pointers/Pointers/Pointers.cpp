#include <iostream>
#include<conio.h>
#include<cstdlib>

using namespace std;
#define LINE '\n';

struct name
{
	char firstName[15];
	char lastName[15];
};
struct student
{
	struct name nm;
	int age;
};

void main()
{
	struct student *stud = new (nothrow)struct student;
	if(stud == 0)
	{
		cout<<"Error";
	}
	cout<<"Enter your first name --> ";
	cin>>stud->nm.firstName;

	cout<<"Enter your last name --> ";
	cin>>stud->nm.lastName;

	cout<<"Enter your age --> ";
	cin>>stud->age;

	cout<<"your name is "<<stud->nm.firstName<<" "<<stud->nm.lastName<<LINE;
	cout<<"Your age is "<<stud->age<<LINE;

	getch();
}


