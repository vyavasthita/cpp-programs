#include <vector>
#include <iterator>
#include<iostream>

class UserData
{
	public:
		UserData()
		{
		}
		~UserData();
		bool addUser(const char*, const char*);
		bool validateUser(const char*, const char*);
};