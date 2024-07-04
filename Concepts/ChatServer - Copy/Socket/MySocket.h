#ifndef __MY_SOCKET_
#define __MY_SOCKET_

#include <WinSock2.h>
#include <iostream>

namespace SocketConnection
{
	class CMySocket
	{
		public:
			CMySocket();
			void SocketStartUp();
			void CreateSocket(int nPortNumber);
			void BindSocket();
			void ListenClient(int nTotalClient = 5);
			void AcceptClient(std::string &r_strClientHost);
			void ConnectClientToServer(const char* const_pcServerIpAddr);
			void CloseSocket();
			void CleanUpSocket();

			void SendMsgToHost(const char *const_pcMsg);
			int ReceiveMsgFromHost(std::string &r_strMsg);

		private:
			int m_nSocketId;
			int m_nPortNumber;
			sockaddr_in st_SocketAddress;
	};
};

#endif __MY_SOCKET_