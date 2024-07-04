#include "ThreadExecption.h"


// ThreadException
ThreadException::ThreadException(const char* exception) 
{
	strErrMsg = exception;
}

std::string ThreadException::getMessage() const 
{
	return strErrMsg;
}
