#include "file_parser.h"
#include "ThreadException.h"

using namespace MyThread;

std::string FileParser::m_stat_strFilePath = "C:\\C++_Practice_2015\\Multithreading2\\ResourceFiles\\thread.txt";

FileParser::FileParser()
{
	ParseFile();	
}

FileParser& FileParser::getInstance()
{
	static FileParser oFileParser;

	return oFileParser;
}

FileParser::~FileParser()
{
	CloseFile();
}

void FileParser::ParseFile()
{
	try
	{
		OpenFile(m_stat_strFilePath);
	}
	catch(const ThreadException& constThreadException)
	{
		std::cout << constThreadException.what();
	}
}

void FileParser::OpenFile(const std::string &const_r_strFileName)
{
	m_fFileStream.open(const_r_strFileName, std::ios::app);

	if (m_fFileStream.fail())
	{
		throw ThreadException("File Access Error\n");
	}
}

void FileParser::WriteToFile(const char* const_cpThreadName, const char* const_cpFileContent)
{
	std::cout << "Thread " << const_cpThreadName << " Writing " << const_cpFileContent << " to file." << std::endl;
	m_fFileStream << "Thread " << const_cpThreadName << " Writing " << const_cpFileContent << " to file." << std::endl;
	CloseFile();
}

void FileParser::CloseFile()
{
	m_fFileStream.close();
}