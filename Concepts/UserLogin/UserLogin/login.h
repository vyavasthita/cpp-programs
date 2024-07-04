#include <iostream>
#include <conio.h>
#include <map>

#ifndef LOGIN_FILE
#define LOGIN_FILE

using namespace std;

enum Choice
{
	NO_CHOICE,
	LOGIN,
	SIGN_UP,
	EXIT
};
class Person
{
	public:
		void welcome();
		void userChoice(unsigned short);
		bool addPerson(string, string);
		bool validatePerson(string, string);

	private:
		map<string , string> person;
		map<string , string>::iterator it;
		pair<map<string , string>::iterator, bool> p;
}object;
#endif LOGIN_FILE