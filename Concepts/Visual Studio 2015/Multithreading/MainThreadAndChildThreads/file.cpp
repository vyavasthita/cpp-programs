#include "file.h"
#include <iostream>
#include <sstream>


using namespace std;


MyFile::MyFile():
	m_pcFilePath("C:\\Raja\\TechnicalStudy\\Source_Code\\CPP_Source_Code\\Visual Studio 2015\\Multithreading\\data.txt")
{

}


void MyFile::writeToFile(const char* info, int count)
{
	m_ofFileStream.open(m_pcFilePath, fstream::app);

	for (int i = 0; i < count; i++)
	{
		m_ofFileStream << "Thread " << info << " has written to file.\n";
	}

	m_ofFileStream.close();
}

void MyFile::readFile()
{
	std::string strLine;

	m_ifFileStream.open(m_pcFilePath);

	while (!m_ifFileStream.eof())
	{
		std::getline(m_ifFileStream, strLine);
	}
}