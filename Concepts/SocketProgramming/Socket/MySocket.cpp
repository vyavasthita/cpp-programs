#include "MySocket.h"

using namespace SocketNamespace;

const int MSG_HEADER_LEN = 6;

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

	nError = bind(m_nSocketId, (struct sockaddr *)&st_SocketAddress, sizeof(struct sockaddr_in));

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

void CMySocket::AcceptClient(std::string &strClientHost)
{
	int nNewSocket;
	int nClientAddressLen = sizeof(struct sockaddr_in);
	struct sockaddr_in st_ClientAddress;

	nNewSocket = accept(m_nSocketId, (struct sockaddr *)&st_ClientAddress, &nClientAddressLen);
	
	if (nNewSocket == SOCKET_ERROR)
	{
		throw "Accept To Client Error";
	}

	char *sAddress = inet_ntoa((struct in_addr)st_ClientAddress.sin_addr);
	unsigned long netAddr = inet_addr(sAddress);

	hostent *p_st_HostInfo = NULL;
	p_st_HostInfo = gethostbyaddr((char *)&netAddr, sizeof(netAddr), AF_INET);
	char *pcHostName = p_st_HostInfo->h_name;

	strClientHost += std::string(pcHostName);

	m_nSocketId = nNewSocket;
}

void CMySocket::ConnectClientToServer(std::string strServerIpAddr)
{	
	struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = inet_addr((char*)strServerIpAddr.c_str());
	serverAddress.sin_port = htons(m_nPortNumber);

	int nError = 0;

	nError = connect(m_nSocketId, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
		
	if (nError == SOCKET_ERROR)
	{
		throw "Connecting Client To Server Error\n";
	}
}

void CMySocket::SendMsgToHost(std::string& strMsg)
{
	int nNumBytes = 0; 
	char msgLength[MSG_HEADER_LEN + 1];

    sprintf(msgLength, "%6d", strMsg.size());
	std::string sendMsg = std::string(msgLength);
    sendMsg += strMsg;

	nNumBytes = send(m_nSocketId, sendMsg.c_str(), sendMsg.size(), 0);

	if (nNumBytes == SOCKET_ERROR)
	{
		throw "Sending Msg Error";
	}
}

int CMySocket::ReceiveMsgFromHost(std::string& strMsg)
{
	int nNumBytes; 

	char msgLength[MSG_HEADER_LEN + 1];
	memset(msgLength, 0, sizeof(msgLength));

	nNumBytes = recv(m_nSocketId, msgLength, MSG_HEADER_LEN, 0);

    if (nNumBytes == SOCKET_ERROR)
	{
		throw "Receiving Msg Error";
	}

	nNumBytes = recv(m_nSocketId, (char*)(strMsg.c_str()), atoi(msgLength), 0);
   
	if (nNumBytes == SOCKET_ERROR)
	{
		throw "Receiving Msg Error";
	}

    return nNumBytes;
}