#include "ClientMain.h"
#include <string>

CClientMain::CClientMain() : m_const_strServerIPAddr("14.96.76.82")
{
}

void CClientMain:: SendMsg()
{
	while(1)
	{
		char sendmsg[MAX_MSG_LEN + 1];
		memset(sendmsg, 0, sizeof(sendmsg));
		std::cout << "[" << m_strLocalHostName.c_str()<< ":SEND]";
		std::cin.getline(sendmsg, MAX_MSG_LEN);

		std::string sendMsg(sendmsg);

		if (sendMsg.compare("Bye") == 0 || sendMsg.compare("bye") == 0) 
		{
			break;
		}

		try
		{
			m_oCMyClient.SendMsgToServer(sendMsg);
		}
		catch(const char* pcError)
		{
			std::cout << pcError;
		}

		std::string clientMessageIn = "";
		int nRecvBytes = 0;

		try
		{
			nRecvBytes = m_oCMyClient.ReceiveMsgFromServer(clientMessageIn);
		}
		catch(const char* pcError)
		{
			std::cout << pcError;
		}

		if ( nRecvBytes == -99 ) 
		{
			break;
		}

		std::cout <<"[RECV:" << m_strServerHostName.c_str() << "]:"<<clientMessageIn.c_str()<<std::endl;
    }
}

void CClientMain::StartClient()
{
	m_oCMyClient.Initialize();

	try
	{
		m_oCMyClient.SetHostInfo();
	}
	catch(const char* pcError)
	{
		std::cout << pcError;
	}

	m_strLocalHostName = m_oCMyClient.GetHostName();

	try
	{
		m_oCMyClient.SetHostInfo(m_const_strServerIPAddr);
	}
	catch(const char* pcError)
	{
		std::cout << pcError;
	}

	std::string strServerIPAddr = m_oCMyClient.GetHostIPAddress();

	m_strServerHostName = m_oCMyClient.GetHostName();

	m_oCMyClient.CreateSocket();

	std::cout << "connecting to the server [" << m_strServerHostName.c_str() << "] ... " << std::endl;

	try
	{
		m_oCMyClient.ConnectClientToServer(strServerIPAddr);
	}
	catch(const char* pcError)
	{
		std::cout << pcError;
	}
}

void main()
{	
	CClientMain oCClientMain;
	oCClientMain.StartClient();
	oCClientMain.SendMsg();
}