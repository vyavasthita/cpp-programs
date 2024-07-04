#include "MyClient.h"
#include <string>

using namespace SocketConnection;

const int CMyClient::m_stat_const_nHostNameLength = 64;

CMyClient::CMyClient() : m_oCMySocket(), m_const_nPortNumber(1200), 
	m_const_pcServerIPAddr("10.9.66.197"), m_const_nMaxMsgLength(1024)
{
}

void CMyClient::SocketConnection()
{
	try
	{
		m_oCMySocket.SocketStartUp();
	}
	catch(const char* const_pcError)
	{
		TerminateConnection();
		TerminateApplication();
	}

	try
	{
		SetClientHostInfo();
		SetServerHostInfo(m_const_pcServerIPAddr);
	}
	catch(const char* const_pcError)
	{
		TerminateConnection();
		TerminateApplication();
	}

	try
	{
		m_oCMySocket.CreateSocket(1200);
	}
	catch(const char* const_pcError)
	{
		TerminateConnection();
		TerminateApplication();
	}

	m_pcServerHostName = GetServerHostName();

	std::cout << "connecting to the server [" << m_pcServerHostName << "] ... " << std::endl;

	try
	{
		m_oCMySocket.ConnectClientToServer(m_const_pcServerIPAddr);
	}
	catch(const char* pcError)
	{
		std::cout << pcError;
	}

	ChatWithServer();
}

void CMyClient::SetClientHostInfo()
{
	int nError = 0;
	char cHostName[m_stat_const_nHostNameLength + 1] = {};

	nError = gethostname(cHostName, m_stat_const_nHostNameLength);

	if (nError == SOCKET_ERROR)
	{
		throw "Host Name Error";
	}

	m_p_stClientHostInfo = gethostbyname(cHostName);

	if (m_p_stClientHostInfo == NULL)
	{
		throw "Host Address Info Error";
	}
}

void CMyClient::SetServerHostInfo(const char *const_pcServerIPAddr)
{
	char *pcHostname = (char*)(const_pcServerIPAddr);

	unsigned long netAddr = inet_addr(const_pcServerIPAddr);

	if (netAddr == SOCKET_ERROR)
	{
		throw "Host Address Info Error";
	}	 

	m_p_stServerHostInfo = gethostbyaddr((char *)&netAddr, sizeof(netAddr), AF_INET);

	if (m_p_stServerHostInfo == NULL)
	{
		throw "Host Address Info Error";
	}
}

char* CMyClient::GetClientHostName()
{
	return m_p_stClientHostInfo->h_name;
}

char* CMyClient::GetClientHostIPAddress()
{
	struct in_addr *addr_ptr;

	addr_ptr = (struct in_addr *)m_p_stClientHostInfo->h_addr_list[0];
	return inet_ntoa(*addr_ptr);
}

char* CMyClient::GetServerHostName()
{
	return m_p_stServerHostInfo->h_name;
}

void CMyClient::ChatWithServer()
{
	int nRecvBytes = 0;
	std::string strRecvMsg = "";
	std::string strMsg = "";

	char *pcClientHostName = GetClientHostName();

	while (1)
	{	
		nRecvBytes = m_oCMySocket.ReceiveMsgFromHost(strRecvMsg); 

		if (strRecvMsg.compare("bye") == 0)
		{
			break;
		}

		std::cout <<"[RECV:" << m_pcServerHostName << "] : "<< strRecvMsg.c_str() << std::endl;

		std::cout << "[" << pcClientHostName << ":SEND] : ";

		std::getline(std::cin, strMsg);

		m_oCMySocket.SendMsgToHost(strMsg.c_str());
	}
}

void CMyClient::TerminateConnection()
{
	try
	{
		m_oCMySocket.CloseSocket();
	}
	catch(const char* const_pcError)
	{
		TerminateApplication();
	}

	try
	{
		m_oCMySocket.CleanUpSocket();
	}
	catch(const char* const_pcError)
	{
		
	}
}

void CMyClient::TerminateApplication()
{
	exit(1);
}

void main()
{
	CMyClient oCMyClient;

	oCMyClient.SocketConnection();
	oCMyClient.TerminateConnection();
}