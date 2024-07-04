#include "MySocket.h"

using namespace SocketConnection;

#define MSG_LENGTH 512

CMySocket::CMySocket()
{
}
void CMySocket::SocketStartUp()
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

void CMySocket::CreateSocket(int nPortNumber)
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

void CMySocket::BindSocket()
{
	int nError = 0;

	nError = bind(m_nSocketId, (struct sockaddr*)&st_SocketAddress, sizeof(struct sockaddr_in));

	if (nError == SOCKET_ERROR)
	{
		throw "Socket Bind Error";
	}
}

void CMySocket::ListenClient(int nTotalClient)
{
	int nError = 0;

	nError = listen(m_nSocketId, nTotalClient);

	if (nError == SOCKET_ERROR)
	{
		throw "Listen To Client Error";
	}
}

void CMySocket::AcceptClient(std::string &r_strClientHost)
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

void CMySocket::ConnectClientToServer(const char* const_pcServerIpAddr)
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

void CMySocket::SendMsgToHost(const char *const_pcMsg)
{
	int nError = 0, nNoOfBytes = 0;
	nError = nNoOfBytes = send(m_nSocketId, (char*)const_pcMsg, strlen(const_pcMsg) + 1, 0);

	if (nError == SOCKET_ERROR)
	{
		throw "Sending Msg Error";
	}
}

int CMySocket::ReceiveMsgFromHost(std::string &r_strMsg)
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

void CMySocket::CloseSocket()
{
	int nError = 0;

	nError = closesocket(m_nSocketId);

	if (nError == INVALID_SOCKET)
	{
		throw "Socket Close Error";
	}
}

void CMySocket::CleanUpSocket()
{
	int nError = 0;

	nError = WSACleanup();

	if (nError == INVALID_SOCKET)
	{
		throw "Socket CleanUp Error";
	}
}