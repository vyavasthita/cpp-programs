#include "logger.h"
#include <fstream>

using namespace std;


const char* Logger::m_filePath = "C:\\Raja\\TechnicalStudy\\Source_Code\\CPP_Source_Code\\Visual Studio 2015\\DesignPatterns\\Singleton\\logs.txt";
bool Logger::bInstance = false;
Logger* Logger::m_Logger;


Logger::Logger()
{
	std::ifstream f;

	f.open(m_filePath, std::ios::app);

	if (f.good())
	{
		cout << "File Opened";
	}
}

Logger::~Logger()
{
	if (m_Logger != NULL)
	{
		m_Logger = NULL;
	}
}

Logger* Logger::getInstance()
{
	if (bInstance)
	{
		m_Logger = new Logger();
		bInstance = true;
	}
	return m_Logger;
}

void Logger::Log(const char* info)
{

}