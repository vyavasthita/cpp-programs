#include <fstream>
#include <iostream>


class MyFile
{
	public:
		MyFile();
		~MyFile();

		void openFile();
		void readFile();
		void writeToFile(char* data);

	private:
		std::fstream m_ifFileStream;
		std::string strFilePath;
};