#include "MyClient.h"

const int CMyClient::m_stat_const_nHostNameLength = 64;

CMyClient::CMyClient() : m_const_nPortNumber(1200), m_const_strServerIPAddr("10.9.66.197")
{
}

void CMyClient::Initialize()
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

void CMyClient::SetHostInfo()
{
	int nError = 0; 
	char cHostName[m_stat_const_nHostNameLength + 1];
	memset(cHostName, 0, sizeof(cHostName));

	nError = gethostname(cHostName, m_stat_const_nHostNameLength);	

	if (nError == SOCKET_ERROR)
	{
		throw "Host Name Error";
	}

	char *pcHostname = "localhost";
	struct addrinfo st_AddrInfo;				 

	m_p_stHostInfo = gethostbyname(cHostName);

	if (m_p_stHostInfo == NULL)
	{
		throw "Host Address Info Error";
	}
}

void CMyClient::SetHostInfo(std::string strServerHostIpAddr)
{
	char *pcHostname = (char*)(strServerHostIpAddr.c_str());

	unsigned long netAddr = inet_addr(strServerHostIpAddr.c_str());

	if (netAddr == SOCKET_ERROR)
	{
		throw "Host Address Info Error";
	}

	struct addrinfo st_AddrInfo;				 

	m_p_stHostInfo = gethostbyaddr((char *)&netAddr, sizeof(netAddr), AF_INET);

	if (m_p_stHostInfo == NULL)
	{
		throw "Host Address Info Error";
	}
}

std::string CMyClient::GetHostName()
{
	//return m_p_stHostAddrInfoRes->ai_canonname;
	return m_p_stHostInfo->h_name;
}

char* CMyClient::GetHostIPAddress()
{
	struct in_addr *addr_ptr;

	addr_ptr = (struct in_addr *)m_p_stHostInfo->h_addr_list[0];
	return inet_ntoa(*addr_ptr);
}

void CMyClient::CreateSocket()
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

void CMyClient::ConnectClientToServer(std::string strClientIpAddr)
{
	try
	{
		m_oCMySocket.ConnectClientToServer(strClientIpAddr);
	}
	catch(const char* pcError)
	{
		throw pcError;
	}
}

void CMyClient::SendMsgToServer(std::string& strMsg)
{
	try
	{
		m_oCMySocket.SendMsgToHost(strMsg);
	}
	catch(const char* pcError)
	{
		throw pcError;
	}
}

int CMyClient::ReceiveMsgFromServer(std::string& strMsg)
{
	int nBytes = 0;
	try
	{
		nBytes = m_oCMySocket.ReceiveMsgFromHost(strMsg);
	}
	catch(const char* pcError)
	{
		std::cout << pcError;
	}
	return nBytes;
}