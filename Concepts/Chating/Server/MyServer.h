#ifndef __MY_SERVER_
#define __MY_SERVER_

#include <WinSock2.h>
#include <iostream>

namespace SocketConnection
{
	class CMyServer
	{
		public:
			CMyServer();

			void SocketStartUp();
			void SocketConnection();

			void CreateSocket(int nPortNumber);
			void BindSocket();
			void ListenClient(int nTotalClient = 5);
			void AcceptClient(std::string &r_strClientHost);
			void ConnectClientToServer(const char* const_pcServerIpAddr);

			void TerminateConnection();
			void TerminateApplication();

			void SetServerHostInfo();
			char* GetServerHostName();
			
			void ChatWithClient();
			void SendMsgToClient(const char* const_pcMsg);
			int RecvMsgFromClient(std::string &r_strMsg);

			void CloseSocket();
			void CleanUpSocket();

		private:
			static const int m_stat_const_nHostNameLength;  
			hostent * m_p_stHostInfo;

			std::string m_strClientHostName;

			const int m_const_nMaxMsgLength;

			int m_nSocketId;
			int m_nPortNumber;
			sockaddr_in st_SocketAddress;
	};
};
#endif __MY_SERVER_