#include "TCPSocket.h"
#include "TCPException.h"
#include "TCPHost.h"

using namespace TCPComm;


CMySocket::CMySocket(int nPortNumber)
{
    m_nPortNumber = nPortNumber;

	try
	{
		if ((m_nSocketId = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		{
			int errorCode;
			char* pcErrorMsg = GetOpenWinSocketErrorMsg();
			throw pcErrorMsg;	
		}
	}
	catch(const CTCPException &const_r_Error)
	{
	}

    /* 
	   set the initial address of client that shall be communicated with to 
	   any address as long as they are using the same port number. 
	   The clientAddr structure is used in the future for storing the actual
	   address of client applications with which communication is going
	   to start
	*/
    m_st_ClientAddr.sin_family = AF_INET;
    m_st_ClientAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    m_st_ClientAddr.sin_port = htons(m_nPortNumber);
}

void CTCPSocket::BindSocket()
{
	try
	{
		if (bind(m_nSocketId, (struct sockaddr *)&m_st_ClientAddr, sizeof(struct sockaddr_in)) == -1)
		{
			int errorCode;
			char* pcErrorMsg = "Socket binding error";
			throw pcErrorMsg;	
		}
	}
	catch(const CTCPException &const_r_Error)
	{
	}
}

void CTCPSocket::ListenToClient(int nNumPorts)
{
	try
	{
		if (listen(m_nSocketId, nNumPorts) == -1)
		{
			int errorCode;
			char* pcErrorMsg = "Client Listening error";
			throw pcErrorMsg;	
		}
	}
	catch(const CTCPException &const_r_Error)
	{
	}
}

CTCPSocket* CTCPSocket::AcceptClient(std::string& r_strClientAddr)
{
	int nNewSocket;   // the new socket file descriptor returned by the accept systme call
	    
	// the length of the client's address
    int nClientAddressLen = sizeof(struct sockaddr_in);
    struct sockaddr_in st_ClientAddress;    // Address of the client that sent data

	try
	{
		if ((nNewSocket = accept(m_nSocketId, (struct sockaddr *)&st_ClientAddress, &nClientAddressLen)) == -1)
		{
			int errorCode;
			char* pcErrorMsg = "Client Accpt Error error";
			throw pcErrorMsg;	
		}
	}
	catch(const CTCPException &const_r_Error)
	{
	}

	// Get the host name given the address
    char *sAddress = inet_ntoa((struct in_addr)st_ClientAddress.sin_addr);
	CTCPHost clientInfo(string(sAddress),ADDRESS);
	char* hostName = clientInfo.getHostName();
    clientHost += string(hostName);
	
    // Create and return the new myTcpSocket object
    myTcpSocket* retSocket = new myTcpSocket();
	retSocket->setSocketId(newSocket);
    return retSocket;
}

char* CMySocket::GetOpenWinSocketErrorMsg()
{
	int nErrorCode = WSAGetLastError();
	char *pcErrorMsg = "";

	if (nErrorCode == WSANOTINITIALISED)
		pcErrorMsg = "Successful WSAStartup must occur before using this function.";
	else if (nErrorCode == WSAENETDOWN )
		pcErrorMsg = "The network subsystem or the associated service provider has failed.";
	else if (nErrorCode == WSAEAFNOSUPPORT )
		pcErrorMsg = "The specified address family is not supported.";
	else if (nErrorCode == WSAEINPROGRESS )
		pcErrorMsg = "A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function.";
	else if (nErrorCode == WSAEMFILE )
		pcErrorMsg = "No more socket descriptors are available.";
	else if (nErrorCode == WSAENOBUFS )
		pcErrorMsg = "No buffer space is available. The socket cannot be created.";
	else if (nErrorCode == WSAEPROTONOSUPPORT )
		pcErrorMsg = "The specified protocol is not supported.";
	else if (nErrorCode == WSAEPROTOTYPE )
		pcErrorMsg = "The specified protocol is the wrong type for this socket.";
	else if (nErrorCode == WSAESOCKTNOSUPPORT )
		pcErrorMsg = "The specified socket type is not supported in this address family.";
	else pcErrorMsg = "unknown problems!";

	return pcErrorMsg;
}

char* CTCPSocket::GetBindErrorMsg()
{
	int nErrorCode = WSAGetLastError();
	char *pcErrorMsg = "";

	return pcErrorMsg;
}

void CTCPSocket::ConnectToServer(const std::string &const_r_strServerName)
{
}