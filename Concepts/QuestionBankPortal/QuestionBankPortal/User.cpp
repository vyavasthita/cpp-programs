#include "User.h"

using namespace std;
namespace Exams
{
	User::User()
	{
		mStrFirstName = "";
		mStrLastName = "";
		mStrUserName = "";
		mStrPassword = "";
		mUserId = iUserID;
	}

	User::~User()
	{
	}
	void User::setFirstName(string firstName)
	{
		mStrFirstName = firstName;
	}

	string User::getFirstName() const
	{
		return mStrFirstName;
	}

	void User::setLastName(string lastName)
	{
		mStrLastName = lastName;
	}

	string User::getLastName() const
	{
		return mStrLastName;
	}

	void User::setUserName(string username)
	{
		mStrUserName = username;
	}

	string User::getUserName() const
	{
		return mStrUserName;
	}

	void User::setPassword(string password)
	{
		mStrPassword = password;
	}

	string User::getPassword() const
	{
		return mStrPassword;
	}

	void User::setUserId(int id)
	{
		mUserId = id;
	}

	int User::getUserId() const
	{
		return mUserId;
	}
}