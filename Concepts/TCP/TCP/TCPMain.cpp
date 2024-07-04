#include <WinSock2.h>
#include <stdio.h>
#include "TCPException.h"
#include "TCPMain.h"
#include "TCPHost.h"
#include <conio.h>
#include "TCPSocket.h"

using namespace TCPComm;

void CTCPMain::StartConnection()
{  
	WSADATA wsaData;

	int nError = WSAStartup(0x101, &wsaData);

	if (nError == SOCKET_ERROR)
	{
		throw "Socket Error";
	}
}

void CTCPMain::ProcessConnection()
{
	CTCPHost oCTCPHost;
	std::string strHostName = oCTCPHost.GetHostName();
	std::string strHostIpAddr = oCTCPHost.GetHostIPAddress();

	std::cout << "Host Name = " << strHostName.c_str() << std::endl;
	std::cout << "Host Ip Address = " << strHostIpAddr.c_str();

	CTCPSocket oCTCPSocket(25);

	oCTCPSocket.BindSocket();
	oCTCPSocket.ListenToClient();
}

int main()
{
	CTCPMain oCTCPMain;
	try
	{
		oCTCPMain.StartConnection();
	}
	catch(const CTCPException &const_r_Error)
	{
	}

	try
	{
		oCTCPMain.ProcessConnection();
	}
	catch(const CTCPException &const_r_Error)
	{
	}
	getch();
}