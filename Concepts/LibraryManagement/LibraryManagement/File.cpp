#include "File.h"
#include <string>

using namespace std;

static unsigned int uiIndex = 0;
bool File::openFile(const char* fileName)
{

	bool bIsSuccess = false;
	
	write.open (fileName , std::ios::out | std::ios::app | std::ios::binary);

	if(write != NULL)
	{
		bIsSuccess = true;
	}

	return bIsSuccess;
}

void File::appendFile(const char* text)
{
	write<<text<<std::endl;
}

void File::fileClose()
{
	write.close();
}

bool File::findUserName(const char *name)
{
	std::string line;
	bool bResult = false;
	
	read.open ("username.bin", std::ios::in | std::ios::app | std::ios::binary);

	if(read.is_open())
	{
		while(!read.eof())
		{
			getline(read, line);
			++uiIndex;

			if(line.compare(name) == 0)
			{
				bResult = true;				
				break;
			}
		}
		read.close();
	}
	return bResult;
}

bool File::findPassword(const char *password)
{
	std::string line;
	bool bResult = false;
	read.open ("password.bin", std::ios::in | std::ios::app | std::ios::binary);

	if(read.is_open())
	{
		while(!read.eof())
		{
			getline(read, line);
			--uiIndex;

			if(uiIndex == 0)
			{
				if(line.compare(password) == 0)
				{
					bResult = true;
					break;
				}
			}
		}
		read.close();
	}

	return bResult;
}

bool File::findBookName(int bookID)
{
	std::string line;
	bool bResult = false;
	read.open ("bookname.bin", std::ios::in | std::ios::app | std::ios::binary);

	if(read.is_open())
	{
		while(!read.eof())
		{	
			getline(read, line);			  	
			--bookID;					   		
			
			if(bookID == 0)
				{		   					
					if(line.size() == 0)
					{		 				
						break;	
					}
					strBookName = line;
					bResult = true;
				}										
		}
		read.close();
	}
	return bResult;
}

bool File::findBookByName(const char* name)
{							
	int id = 0;
	std::string line;
	bool bResult = false;
	read.open ("bookname.bin", std::ios::in | std::ios::app | std::ios::binary);

	if(read.is_open())
	{	
		while(!read.eof())
		{	
			getline(read, line);
			line.erase(line.size() - 1 , line.size());
			++id;
			
			if(line.compare(name) == 0)
				{
					strBookName = line;
					setBookID(id);
					bResult = true;
					break;
				}										
		}
		read.close();
	}
	else
	{
		std::cout<<"File Couldnt opened"<<endl;
	}
	return bResult;
}
string File::getBookName()
{
	return strBookName;
}
void File::setBookID(int id)
{
	bookID = id;
}
int File::getBookID(const char* bookName)
{
	return bookID;
}
map<int, string> File::getBookDetails()
{
	int key = 0;
	string line;
	read.open ("bookname.bin", std::ios::in | std::ios::app | std::ios::binary);
	if(read.is_open())
	{	
		while(!read.eof())
		{	
			getline(read, line); 
			key++;				 			
			bookMap.insert(pair<int, string>(key, line));			
		}
		read.close();
	}
	else
	{
		std::cout<<"File Couldnt opened"<<endl;
	}
	return bookMap;
}