#include<iostream>
#include <map>

class Book
{
	public:
		Book()
		{
			
		}
		void displayInfo();
		void bookIssue();
		void returnBook();
		void setTotalBooks(int);
		int getTotalBooks();
		std::string getDate(int);
		std::string getDay(int);
		std::string getMonth(int);
		std::string getYear(int);
		char* getCurrentTime();
		void printBookDetails();

	private:
		int iTotalBooks;
		int iBookID;
		std::map<int, std::string> bookMap;
		std::map<int, std::string>::iterator it;
};