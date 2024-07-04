#include "thread_exception.h"

ThreadException::ThreadException() : m_const_cErrorMsg("")
{
}

ThreadException::ThreadException(const char* errorMsg) : m_const_cErrorMsg(errorMsg)
{
}

ThreadException::~ThreadException()
{
}

const char* ThreadException::getErrorMsg() const
{
	return m_const_cErrorMsg;
}