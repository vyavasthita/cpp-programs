#include <map>

namespace LMS
{
	class Login
	{
		public:
			Login();
			bool validateCredential(char*, char*);
			bool addUserName(std::string);
			bool findUser(std::string);

		private:
			char *name;
			char *password;
			unsigned int key;

			std::map<unsigned int, std::string> mapUserName;
	};
}