#include <iostream>

namespace Records
{
	const int kDefaultStartingSalary = 30000;

	class Employee
	{
		public:
			Employee();
			void promote(int inRaiseAmount = 1000);
			void demote(int inDemeritAmount = 1000);
			void hire();
			void fire();
			void display();

			//Accessors and setter
			void setFirstName(std::string inFirstName);
			std::string getFirstName();			
			void setLastName(std::string inLastName);
			std::string getLastName();
			void setEmplyeeNumber(int inEmployeeNumber);
			int getEmployeeNumber();
			void setSalary(int inNewSalary);
			int getSalary();
			bool getIsHired();

		private:
			std::string mFirstName;
			std::string mLastName;
			int mEmployeeNumber;
			int mSalary;
			bool fHired;
	};
}