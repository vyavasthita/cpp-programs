#include "myexception.h"

using namespace ThreadNameSpace;

CThreadException::CThreadException(const char* cpThreadException) :
m_const_cpThreadException(cpThreadException)
{
}

CThreadException::~CThreadException()
{
}

const char* CThreadException::what() const
{
	return m_const_cpThreadException;
}

CFileException::CFileException(const char* cpFileException) :
m_const_cpFileException(cpFileException)
{
}

CFileException::~CFileException()
{
}

const char* CFileException::what() const
{
	return m_const_cpFileException;
}