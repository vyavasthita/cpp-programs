#include "MyServer.h"
#include <ws2tcpip.h>

const int CMyServer::m_stat_const_nHostNameLength = 64;

CMyServer::CMyServer() : m_const_nPortNumber(1200)
{
	
}

void CMyServer::SetHostInfo()
{
	int nError = 0; 
	char cHostName[m_stat_const_nHostNameLength + 1];
	memset(cHostName, 0, sizeof(cHostName));

	nError = gethostname(cHostName, m_stat_const_nHostNameLength);
	

	if (nError == SOCKET_ERROR)
	{
		throw "Host Name Error";
	}

	/*char *pcHostname = "localhost";
	struct addrinfo st_AddrInfo;*/				 

	/*nError = getaddrinfo(pcHostname, NULL, &st_AddrInfo, &m_p_stHostAddrInfoRes);

	if (nError != 0)
	{
		throw "Host Address Info Error";
	}

	freeaddrinfo(m_p_stHostAddrInfoRes);*/

	m_p_stHostInfo = gethostbyname(cHostName);

	if (m_p_stHostInfo == NULL)
	{
		throw "Host Address Info Error";
	}
}

std::string CMyServer::GetHostName()
{
	return m_p_stHostInfo->h_name;
}

char* CMyServer::GetHostIPAddress()
{
	struct in_addr addr_ptr;

	addr_ptr.S_un.S_addr = *(u_long *)m_p_stHostInfo->h_addr_list[0];
	return inet_ntoa(addr_ptr);
}

void CMyServer::Initialize()
{
	try
	{
		m_oCMySocket.SocketStartUp();
	}
	catch(const char* pcError)
	{
		std::cout << pcError;
	}
}

void CMyServer::CreateSocket()
{
	try
	{
		m_oCMySocket.CreateSocket(m_const_nPortNumber);
	}
	catch(const char* pcError)
	{
		std::cout << pcError;
	}
}

void CMyServer::BindSocket()
{
	try
	{
		m_oCMySocket.BindSocket();
	}
	catch(const char* pcError)
	{
		std::cout << pcError;
	}
}

void CMyServer::ListenClient()
{
	try
	{
		m_oCMySocket.ListenClient();
	}
	catch(const char* pcError)
	{
		std::cout << pcError;
	}
}

void CMyServer::AcceptClient(std::string &strClientHost)
{
	try
	{
		m_oCMySocket.AcceptClient(strClientHost);
	}
	catch(const char* pcError)
	{
		throw pcError;
	}
}

void CMyServer::SendMsgToClient(std::string& strMsg)
{
	m_oCMySocket.SendMsgToHost(strMsg);
}

int CMyServer::ReceiveMsgFromClient(std::string& strMsg)
{
	int nBytes = m_oCMySocket.ReceiveMsgFromHost(strMsg);
	return nBytes;
}