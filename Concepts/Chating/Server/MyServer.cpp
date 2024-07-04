#include "MyServer.h"
#include <string>

using namespace SocketConnection;

const int CMyServer::m_stat_const_nHostNameLength = 64;

CMyServer::CMyServer() : m_const_nMaxMsgLength(1024)
{
}

void CMyServer::SocketStartUp()
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

void CMyServer::SocketConnection()
{
	try
	{
		SetServerHostInfo();
	}
	catch(const char* const_pcError)
	{
		throw const_pcError;
	}

	try
	{
		CreateSocket(1200);
	}
	catch(const char* const_pcError)
	{
		throw const_pcError;
	}

	try
	{
		BindSocket();
	}
	catch(const char* const_pcError)
	{
		throw const_pcError;
	}

	try
	{
		ListenClient();
	}
	catch(const char* const_pcError)
	{
		throw const_pcError;
	}

	std::cout << "Waiting for Client Connection\n";

	try
	{
		AcceptClient(m_strClientHostName);
	}
	catch(const char *const_pcError)
	{
		throw const_pcError;
	}

	std::cout << "A client from [" << m_strClientHostName.c_str() << "] is connected!" << std::endl;

	ChatWithClient();
}

void CMyServer::CreateSocket(int nPortNumber)
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

void CMyServer::BindSocket()
{
	int nError = 0;

	nError = bind(m_nSocketId, (struct sockaddr*)&st_SocketAddress, sizeof(struct sockaddr_in));

	if (nError == SOCKET_ERROR)
	{
		throw "Socket Bind Error";
	}
}

void CMyServer::ListenClient(int nTotalClient)
{
	int nError = 0;

	nError = listen(m_nSocketId, nTotalClient);

	if (nError == SOCKET_ERROR)
	{
		throw "Listen To Client Error";
	}
}

void CMyServer::AcceptClient(std::string &r_strClientHost)
{
	int nNewSocket;
	int nClientAddressLen = sizeof(struct sockaddr_in);
	struct sockaddr_in st_ClientAddress;	   //address of client

	nNewSocket = accept(m_nSocketId, (struct sockaddr *)&st_ClientAddress, &nClientAddressLen);

	if (nNewSocket == SOCKET_ERROR)
	{
		throw "Accept To Client Error";
	}

	char *sAddress = inet_ntoa((struct in_addr)st_ClientAddress.sin_addr);
	unsigned long netAddr = inet_addr(sAddress);	  //IP address

	hostent *p_st_HostInfo = NULL;
	p_st_HostInfo = gethostbyaddr((char *)&netAddr, sizeof(netAddr), AF_INET);	//Host information of client, given the IP address

	char *pcHostName = p_st_HostInfo->h_name;			  //Host name of the client

	r_strClientHost += std::string(pcHostName);

	m_nSocketId = nNewSocket;
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

		SendMsgToClient(strMsg.c_str());

		RecvMsgFromClient(strRecvMsg);

		if (strRecvMsg.compare("bye") == 0)
		{
			break;
		}

		std::cout <<"[RECV:" << m_strClientHostName << "] : "<<strRecvMsg.c_str()<<std::endl;
	}
}

void CMyServer::SendMsgToClient(const char* const_pcMsg)
{
	int nError = 0, nNoOfBytes = 0;
	nError = nNoOfBytes = send(m_nSocketId, (char*)const_pcMsg, strlen(const_pcMsg) + 1, 0);

	if (nError == SOCKET_ERROR)
	{
		throw "Sending Msg Error";
	}
}

int CMyServer::RecvMsgFromClient(std::string &r_strMsg)
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

void CMyServer::CloseSocket()
{
	int nError = 0;

	nError = closesocket(m_nSocketId);

	if (nError == INVALID_SOCKET)
	{
		throw "Socket Close Error";
	}
}

void CMyServer::CleanUpSocket()
{
	int nError = 0;

	nError = WSACleanup();

	if (nError == INVALID_SOCKET)
	{
		throw "Socket CleanUp Error";
	}
}

void CMyServer::TerminateConnection()
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

void CMyServer::TerminateApplication()
{
	exit(1);
}

void main()
{
	CMyServer oCMyServer;

	try
	{
		oCMyServer.SocketStartUp();
	}
	catch(const char* const_pcError)
	{
	}

	oCMyServer.SocketConnection();
	oCMyServer.TerminateConnection();
}