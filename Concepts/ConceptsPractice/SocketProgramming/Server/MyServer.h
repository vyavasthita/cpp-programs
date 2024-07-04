#ifndef __MY_SERVER_
#define __MY_SERVER_

#include "MySocket.h"
#include <iostream>

using namespace SocketNamespace;

class CMyServer
{
	public:
		CMyServer();
		void SetHostInfo();
		std::string GetHostName();
		char* GetHostIPAddress();

		void Initialize();
		void CreateSocket();
		void BindSocket();
		void ListenClient();
		void AcceptClient(std::string &strClientHost);

		void SendMsgToClient(std::string& strMsg);
		int ReceiveMsgFromClient(std::string& strMsg);

	private:
		CMySocket m_oCMySocket;
		const int m_const_nPortNumber;
		static const int m_stat_const_nHostNameLength;
		struct addrinfo *m_p_stHostAddrInfoRes;  
		hostent * m_p_stHostInfo;
};
#endif __MY_SERVER_