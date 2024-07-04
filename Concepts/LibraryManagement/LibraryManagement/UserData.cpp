#include "UserData.h"
#include <iostream>
#include <fstream>
#include <string>
#include "File.h"

UserData::~UserData()
{
};

bool UserData::validateUser(const char *name, const char* password)
{
	bool bResult = false;
	File fileObj;

	bResult = fileObj.findUserName(name);
	if(bResult)
	{
		bResult = fileObj.findPassword(password);
	}
	return bResult;
}

bool UserData::addUser(const char* name, const char* password)
{
	bool bResult = false;
	File fileObj;

	if(fileObj.findUserName(name))
	{
		return bResult;
	}

	char* userName = "username.bin";
	char* userPassword = "password.bin";
	
	bResult = fileObj.openFile(userName);

	if(bResult)
	{
		fileObj.appendFile(name);
		fileObj.fileClose();
	}

	bResult = fileObj.openFile(userPassword);

	if(bResult)
	{
		fileObj.appendFile(password);
		fileObj.fileClose();
	}
	return bResult;
}