#include <iostream>
#include <exception>
#include <conio.h>
#include <sstream>
#include <string>

using namespace std;

class FileError : public runtime_error
{
	public:
		FileError(const string& fileIn) : runtime_error(""), mFile(fileIn) 
		{
		}

		virtual ~FileError() throw()
		{
		}

		virtual const char* what() const throw() 
		{ 
			return mMsg.c_str(); 
		}
		string getFileName() 
		{ 
			return mFile; 
		}
		
	protected:
		string mFile, mMsg;
};

class FileOpenError : public FileError
{
	public:
		FileOpenError(const string& fileNameIn);

		virtual ~FileOpenError() throw()
		{
		}
};

FileOpenError::FileOpenError(const string& fileNameIn) : FileError(fileNameIn)
{
	mMsg = "Unable to open File" + fileNameIn;
}

class FileReadError : public FileError
{
	public:
		FileReadError(const string& fileNameIn, int lineNumIn);
		virtual ~FileReadError() throw() {}
		int getLineNum() 
		{ 
			return mLineNum; 
		}
	protected:
		int mLineNum;
};
	
FileReadError::FileReadError(const string& fileNameIn, int lineNumIn) : FileError(fileNameIn), mLineNum(lineNumIn)
{
	ostringstream ostr;
	ostr << "Error reading " << fileNameIn << " at line " << lineNumIn;
	mMsg = ostr.str();
}

void main()
{
	

	getch();
}