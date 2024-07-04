#include "ThreadException.h"

using namespace MyThread;

ThreadException::ThreadException(const char *const_pcErrorMsg) : m_const_pcErrorMessage(const_pcErrorMsg)
{
}

ThreadException::~ThreadException()
{
}

const char* ThreadException::what() const throw()
{
	return m_const_pcErrorMessage;
}