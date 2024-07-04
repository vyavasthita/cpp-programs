#ifndef __MY_CLIENT_
#define __MY_CLIENT_

#include "MySocket.h"
#include <iostream>

using namespace SocketNamespace;

class CMyClient
{
	public:
		CMyClient();
		void SetHostInfo();
		void SetHostInfo(std::string strServerHostIpAddr);
		std::string GetHostName();
		char* GetHostIPAddress();

		void Initialize();
		void CreateSocket();
		void ConnectClientToServer(std::string strClintIpAddr);

		void SendMsgToServer(std::string& strMsg);

		int ReceiveMsgFromServer(std::string& strMsg);

	private:
		CMySocket m_oCMySocket;
		const int m_const_nPortNumber;
		static const int m_stat_const_nHostNameLength;
		struct addrinfo *m_p_stHostAddrInfoRes;  
		hostent * m_p_stHostInfo;

		const std::string m_const_strServerIPAddr;
};
#endif __MY_CLIENT_