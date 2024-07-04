#include "MyClient.h"
#include <string>

using namespace SocketConnection;

const int CMyClient::m_stat_const_nHostNameLength = 64;

CMyClient::CMyClient() : m_const_pcServerIPAddr("10.9.66.197"), m_const_nMaxMsgLength(1024)
{
}

void CMyClient::SocketStartUp()
{
	int nError = 0;

	WSADATA wsaData;
	WORD wVersionRequested = 0;
	wVersionRequested = MAKEWORD(2,2);

	nError = WSAStartup(wVersionRequested, &wsaData);

	if (nError == SOCKET_ERROR)
	{
		throw "Socket Startup Error";
	}
}

void CMyClient::SocketConnection()
{
	try
	{
		SocketStartUp();
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
		CreateSocket(1200);
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
		ConnectClientToServer(m_const_pcServerIPAddr);
	}
	catch(const char* pcError)
	{
		std::cout << pcError;
	}

	ChatWithServer();
}

void CMyClient::CreateSocket(int nPortNumber)
{
	m_nPortNumber = nPortNumber;

	m_nSocketId = socket(AF_INET, SOCK_STREAM, 0);

	if (m_nSocketId == INVALID_SOCKET)
	{
		throw "Socket Creation Error";
	}

	st_SocketAddress.sin_family = AF_INET;
	st_SocketAddress.sin_port = htons(m_nPortNumber);
	st_SocketAddress.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
}

void CMyClient::ConnectClientToServer(const char* const_pcServerIpAddr)
{
	struct sockaddr_in serverAddress;

    serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = inet_addr((char*)const_pcServerIpAddr);
	serverAddress.sin_port = htons(m_nPortNumber);

	int nError = 0;

	nError = connect(m_nSocketId, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
		
	if (nError == SOCKET_ERROR)
	{
		throw "Connecting Client To Server Error";
	}
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
		RecvMsgFromServer(strRecvMsg); 

		if (strRecvMsg.compare("bye") == 0)
		{
			break;
		}

		std::cout <<"[RECV:" << m_pcServerHostName << "] : "<< strRecvMsg.c_str() << std::endl;

		std::cout << "[" << pcClientHostName << ":SEND] : ";

		std::getline(std::cin, strMsg);

		SendMsgToServer(strMsg.c_str());
	}
}

void CMyClient::SendMsgToServer(const char* const_pcMsg)
{
	int nError = 0, nNoOfBytes = 0;
	nError = nNoOfBytes = send(m_nSocketId, (char*)const_pcMsg, strlen(const_pcMsg) + 1, 0);

	if (nError == SOCKET_ERROR)
	{
		throw "Sending Msg Error";
	}
}

int CMyClient::RecvMsgFromServer(std::string &r_strMsg)
{
	int nError = 0, nNoOfBytes = 0;
	r_strMsg.clear();

	char cRecvMsg;

	while (true)
	{
		nError = nNoOfBytes = recv(m_nSocketId, &cRecvMsg, 1, 0);

		if (cRecvMsg == NULL)
		{
			break;
		}
		else
		{
			r_strMsg.push_back(cRecvMsg);
		}	
	}

	if (nError == SOCKET_ERROR)
	{
		throw "Receiving Msg Error";
	}

	return nNoOfBytes;
}

void CMyClient::CloseSocket()
{
	int nError = 0;

	nError = closesocket(m_nSocketId);

	if (nError == INVALID_SOCKET)
	{
		throw "Socket Close Error";
	}
}

void CMyClient::CleanUpSocket()
{
	int nError = 0;

	nError = WSACleanup();

	if (nError == INVALID_SOCKET)
	{
		throw "Socket CleanUp Error";
	}
}

void CMyClient::TerminateConnection()
{
	try
	{
		CloseSocket();
	}
	catch(const char* const_pcError)
	{
		TerminateApplication();
	}

	try
	{
		CleanUpSocket();
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
	std::cout << "*****************Chat Application*****************\n";
	std::cout << "***************Developer : Dilip Sharma***********\n";

	CMyClient oCMyClient;

	oCMyClient.SocketConnection();
	oCMyClient.TerminateConnection();
}