#include <iostream>

#ifndef USER_INFO
#define USER_INFO
namespace Exams
{
	const int iUserID = 0;
	class User
	{
		public:
			User();
			~User();
			void setFirstName(std::string);
			std::string getFirstName() const;
			void setLastName(std::string);
			std::string getLastName() const;
			void setUserName(std::string);
			std::string getUserName() const;
			void setPassword(std::string);
			std::string getPassword() const;
			void setUserId(int);
			int getUserId() const;
		private:
			std::string mStrFirstName;
			std::string mStrLastName;
			std::string mStrUserName;
			std::string mStrPassword;
			int mUserId;
	};
}
#endif USER_INFO