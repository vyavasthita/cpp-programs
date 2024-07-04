#ifndef __MY_SOCKET_
#define __MY_SOCKET_

#include <WinSock2.h>
#include <iostream>

namespace SocketNamespace
{
	const int MAX_MSG_LEN = 1024;

	class CMySocket
	{
		public:
			void SocketStartUp();
			void CreateSocket(int nPortNumber);
			void BindSocket();
			void ListenClient(int nTotalClient = 5);
			void AcceptClient(std::string &strClientHost);
			void ConnectClientToServer(std::string strServerIpAddr);
			void CloseSocket();

			void SendMsgToHost(std::string& strMsg);
			int ReceiveMsgFromHost(std::string& strMsg);

		private:
			int m_nSocketId;
			int m_nPortNumber;
			sockaddr_in st_SocketAddress;
	};
};

#endif __MY_SOCKET_