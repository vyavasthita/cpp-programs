
namespace LMS
{
	class WelCome
	{
		public:
			void Welcome();//ctor
			void userName();
			void password();
			void signUpUser(std::string, std::string);
			void proceed();
			void welcomeScreen();
			void clearScreen()
			{
				system("cls");
			}
			void selectedChoice(unsigned int);
			unsigned int choice;
		private:
			enum choice
			{
				SIGN_IN = 1,
				SIGN_UP,
				EXIT
			}select;
			struct user
			{
				char name[10];
				char password[10];
			}userInfo;
	};
}