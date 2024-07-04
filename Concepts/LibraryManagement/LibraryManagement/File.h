#include <iostream>
#include <fstream>
#include <map>


class File
{
	public:
		File()
		{
			
		}
		bool openFile(const char*);
		void appendFile(const char*);
		bool findUserName(const char *);
		bool findPassword(const char *);
		bool findBookName(int);
		bool findBookByName(const char*);
		std::string getBookName();
		void fileClose();
		void setBookID(int id);
		int getBookID(const char*);
		std::map<int, std::string> getBookDetails();

	private:
		std::ifstream read;
		std::ofstream write;	
		std::string strBookName;
		int bookID;
		std::map<int, std::string> bookMap;
};
  