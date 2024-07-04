#include "MyServer.h"
#include "ServerLog.h"
#include <string>

using namespace SocketConnection;

const int CMyServer::m_stat_const_nHostNameLength = 64;

CMyServer::CMyServer() : m_oCMySocket(), 
	m_const_nPortNumber(1200), m_const_nMaxMsgLength(1024)
{
}

void CMyServer::SocketConnection()
{
	try
	{
		m_oCMySocket.SocketStartUp();
	}
	catch(const char* const_pcError)
	{
		CServerLog::GetInstance()->Log(const_pcError);
		TerminateConnection();
		TerminateApplication();
	}

	CServerLog::GetInstance()->Log("Server:Start Up Successful");

	try
	{
		SetServerHostInfo();
	}
	catch(const char* const_pcError)
	{
		CServerLog::GetInstance()->Log(const_pcError);
		TerminateConnection();
		TerminateApplication();
	}

	try
	{
		m_oCMySocket.CreateSocket(1200);
	}
	catch(const char* const_pcError)
	{
		CServerLog::GetInstance()->Log(const_pcError);
		TerminateConnection();
		TerminateApplication();
	}
	
	CServerLog::GetInstance()->Log("Server : Socket Creation Successful");

	try
	{
		m_oCMySocket.BindSocket();
	}
	catch(const char* const_pcError)
	{
		CServerLog::GetInstance()->Log(const_pcError);
		TerminateConnection();
		TerminateApplication();
	}

	CServerLog::GetInstance()->Log("Server : Socket Bind Successful");

	try
	{
		m_oCMySocket.ListenClient();
	}
	catch(const char* const_pcError)
	{
		CServerLog::GetInstance()->Log(const_pcError);
		TerminateConnection();
		TerminateApplication();
	}

	CServerLog::GetInstance()->Log("Server : Listen To Client Successful");

	try
	{
		m_oCMySocket.AcceptClient(m_strClientHostName);
	}
	catch(const char* const_pcError)
	{
		CServerLog::GetInstance()->Log(const_pcError);
		TerminateConnection();
		TerminateApplication();
	}

	CServerLog::GetInstance()->Log("Server : Accept To Client Successful");
	std::cout << "A client from [" << m_strClientHostName.c_str() << "] is connected!" << std::endl;

	ChatWithClient();
}

void CMyServer::SetServerHostInfo()
{
	int nError = 0;
	char cHostName[m_stat_const_nHostNameLength + 1] = {};

	nError = gethostname(cHostName, m_stat_const_nHostNameLength);

	if (nError == SOCKET_ERROR)
	{
		throw "Host Name Error";
	}

	m_p_stHostInfo = gethostbyname(cHostName);

	if (m_p_stHostInfo == NULL)
	{
		throw "Host Address Info Error";
	}
}

char* CMyServer::GetServerHostName()
{
	return m_p_stHostInfo->h_name;
}

void CMyServer::ChatWithClient()
{
	char *pcServerHostName = GetServerHostName();
	std::string strMsg = "";

	int nRecvBytes = 0;
	std::string strRecvMsg = "";

	while (1)
	{
		std::cout << "[" << pcServerHostName<< ":SEND] : ";
		std::getline(std::cin, strMsg);

		m_oCMySocket.SendMsgToHost(strMsg.c_str());

		nRecvBytes = m_oCMySocket.ReceiveMsgFromHost(strRecvMsg);

		if (strRecvMsg.compare("bye") == 0)
		{
			break;
		}

		std::cout <<"[RECV:" << m_strClientHostName << "] : "<<strRecvMsg.c_str()<<std::endl;
	}
}

void CMyServer::TerminateConnection()
{
	try
	{
		m_oCMySocket.CloseSocket();
	}
	catch(const char* const_pcError)
	{
		CServerLog::GetInstance()->Log(const_pcError);
		TerminateApplication();
	}

	CServerLog::GetInstance()->Log("Server : Socket Close Successful");

	try
	{
		m_oCMySocket.CleanUpSocket();
	}
	catch(const char* const_pcError)
	{
		CServerLog::GetInstance()->Log(const_pcError);
	}
}

void CMyServer::TerminateApplication()
{
	exit(1);
}

void main()
{
	CMyServer oCMyServer;

	oCMyServer.SocketConnection();
	oCMyServer.TerminateConnection();
}