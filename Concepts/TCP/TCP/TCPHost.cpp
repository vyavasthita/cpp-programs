#include "TCPHost.h"

using namespace TCPComm;

CTCPHost::CTCPHost()
{
	char szHostName[m_const_unHostNameLength];
	memset(szHostName, 0, sizeof(szHostName));
	gethostname(szHostName, m_const_unHostNameLength);

	st_HostName = gethostbyname(szHostName);
	
	if (st_HostName == NULL)
	{
		throw GetTCPErrorMsg().c_str();
	}
	
}

std::string CTCPHost::GetTCPErrorMsg()
{
	int nErrorCode = WSAGetLastError();
	std::string strErrorMsg = "";

	if ( nErrorCode == WSANOTINITIALISED )
		strErrorMsg = "need to call WSAStartup to initialize socket system on Window system.";
	else if ( nErrorCode == WSAENETDOWN )
		strErrorMsg = "The network subsystem has failed.";
	else if ( nErrorCode == WSAHOST_NOT_FOUND )
		strErrorMsg = "Authoritative Answer Host not found.";
	else if ( nErrorCode == WSATRY_AGAIN )
		strErrorMsg = "Non-Authoritative Host not found, or server failure.";
	else if ( nErrorCode == WSANO_RECOVERY )
		strErrorMsg = "Nonrecoverable error occurred.";
	else if ( nErrorCode == WSANO_DATA )
		strErrorMsg = "Valid name, no data record of requested type.";
	else if ( nErrorCode == WSAEINPROGRESS )
		strErrorMsg = "A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function.";
	else if ( nErrorCode == WSAEFAULT )
		strErrorMsg = "The name parameter is not a valid part of the user address space.";
	else if ( nErrorCode == WSAEINTR )
		strErrorMsg = "A blocking Windows Socket 1.1 call was canceled through WSACancelBlockingCall.";

	return strErrorMsg;
}

char* CTCPHost::GetHostName()
{
	return st_HostName->h_name;
}

char* CTCPHost::GetHostIPAddress()
{
	struct in_addr *addr_ptr;
	// the first address in the list of host addresses
    addr_ptr = (struct in_addr *)*st_HostName->h_addr_list;
	// changed the address format to the Internet address in standard dot notation
    return inet_ntoa(*addr_ptr);
}