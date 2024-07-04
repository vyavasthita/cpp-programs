#include "fileparser.h"
#include "myexception.h"



using namespace ThreadNameSpace;

const char* CFileParser::m_const_cpFilePath = "C:\\Raja\\TechnicalStudy\\Source_Code\\CPP_Source_Code\\temp_file.txt";

CFileParser::CFileParser(CMutex* pMutex) :
m_cpMutex(pMutex)
{
}

CFileParser::~CFileParser()
{
}

void CFileParser::openFile()
{
	
	m_fileStream.open(m_const_cpFilePath, std::ios::app);

	if (m_fileStream.fail())
	{
		throw CFileException("Unable to open file");
	}
}

void CFileParser::readFile()
{
}

void CFileParser::writeToFile(char* cpThreadName, const char* cpContent)
{
	bool bResourceAvailable = FALSE;

	bResourceAvailable = TRUE;//m_cpMutex->wait();

	if (bResourceAvailable)
	{
		openFile();

		m_fileStream << cpThreadName << ":" << cpThreadName << std::endl;
	}
}

void CFileParser::closeFile()
{
}