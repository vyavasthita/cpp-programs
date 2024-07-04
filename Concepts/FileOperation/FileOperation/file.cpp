#include "file.h"
#include <sstream>
#include <string>


MyFile::MyFile()
{
	strFilePath = "C:\\C++_Practice_2015\\FileOperation\\Files\\tempfile.txt";
}

MyFile::~MyFile()
{
	m_ifFileStream.close();
}

void MyFile::openFile()
{
	m_ifFileStream.open(strFilePath, std::ios::app);

	if (m_ifFileStream.fail())
	{
		std::cout << "File Open Error\n";
	}
	else
	{
		std::cout << "File Opened Successfully\n";
	}
}

void MyFile::readFile()
{
	std::string strConfigLine = "";

	while(m_ifFileStream.good())
	{
		std::getline(m_ifFileStream, strConfigLine);

		std::cout << strConfigLine << std::endl;
	}
}

void MyFile::writeToFile(char* data)
{
	m_ifFileStream << data << std::endl;
}