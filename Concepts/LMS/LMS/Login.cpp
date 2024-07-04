#include "Login.h"
#include <iostream>

using namespace LMS;

Login::Login()
{
	name = "";
	password = "";
	key = 0;
}
bool Login::validateCredential(char * n, char *p)
{
	bool found = false;
	return found;
}

bool Login::addUserName(std::string name)
{
	bool flag = false;
	flag = findUser(name);

	if(flag == false)
	{
		mapUserName.insert(std::pair<unsigned int, std::string>(key++, name));
	}
	return flag;
}
bool Login::findUser(std::string name)
{
	bool found = false;
	std::map<unsigned int, std::string>::iterator it = mapUserName.begin();
	
	for(it; it != mapUserName.end(); it++)
	{
		if(it->second.compare(name) == true)
		{
			found = true;
			break;
		}
	}
	return found;
}
