#include "ServerMain.h"
#include <string>

CServerMain::CServerMain()
{
}

void CServerMain::SendMsg()
{
	while (1)
	{
		std::string strClientMessageIn = "";

		int nNumBytes = m_oCMyServer.ReceiveMsgFromClient(strClientMessageIn);

		if (nNumBytes == -99 ) 
		{
			break;
		}

		std::cout <<"[RECV:" << m_strClientHostName.c_str() << "]:"<<strClientMessageIn.c_str()<<std::endl;

		char sendmsg[MAX_MSG_LEN + 1];
		memset(sendmsg, 0, sizeof(sendmsg));

		std::cout << "[" << m_strLocalHostName.c_str() << ":SEND]";
		std::cin.getline(sendmsg, MAX_MSG_LEN);

		if (nNumBytes == -99 ) 
		{
			break;
		}

		std::string sendMsg(sendmsg);

		if (sendMsg.compare("Bye") == 0 || sendMsg.compare("bye") == 0)
		{
			break;
		}
	
		m_oCMyServer.SendMsgToClient(sendMsg);
	}
}

void CServerMain::StartServer()
{
	m_oCMyServer.Initialize();

	try
	{
		m_oCMyServer.SetHostInfo();
	}
	catch(const char* pcError)
	{
		std::cout << pcError;
	}

	m_strLocalHostName = m_oCMyServer.GetHostName();
	std::string strLocalHostIPAddr = m_oCMyServer.GetHostIPAddress();

	m_oCMyServer.CreateSocket();
	m_oCMyServer.BindSocket();
	m_oCMyServer.ListenClient();

	std::cout << "Server is waiting for client connecction ... " << std::endl;

	try
	{
		m_oCMyServer.AcceptClient(m_strClientHostName);
	}
	catch(const char* pcError)
	{
		std::cout << pcError;
	}
	std::cout << "A client from [" << m_strClientHostName.c_str() << "] is connected!" << std::endl;
}

void main()
{
	CServerMain oCServerMain;
	oCServerMain.StartServer();
	oCServerMain.SendMsg();
}