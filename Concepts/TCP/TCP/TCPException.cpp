#include "TCPException.h"

using namespace TCPComm;

CTCPException::CTCPException(const char* const_pcErrorMsg) : m_const_pcErrorMsg(const_pcErrorMsg)
{
	
}

const char* CTCPException::GetErrorMsg()
{
	return m_const_pcErrorMsg;
}