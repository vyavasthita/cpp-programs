#ifndef __MY_CLIENT_
#define __MY_CLIENT_

#include <WinSock2.h>
#include <iostream>

namespace SocketConnection
{
	class CMyClient
	{
		public:
			CMyClient();

			void SocketStartUp();
			void SocketConnection();
			void CreateSocket(int nPortNumber);
			void ConnectClientToServer(const char* const_pcServerIpAddr);

			void TerminateConnection();
			void TerminateApplication();

			void SetClientHostInfo();
			void SetServerHostInfo(const char *const_pcServerIPAddr);

			char* GetClientHostName();
			char* GetClientHostIPAddress();

			char* GetServerHostName();
			char* GetServerHostIPAddress();

			void ChatWithServer();

			void SendMsgToServer(const char* const_pcMsg);
			int RecvMsgFromServer(std::string &r_strMsg);

			void CloseSocket();
			void CleanUpSocket();

		private:
			static const int m_stat_const_nHostNameLength;

			hostent *m_p_stClientHostInfo, *m_p_stServerHostInfo;

			const char* m_const_pcServerIPAddr;

			char *m_pcLocalHostName, *m_pcServerHostName;

			const int m_const_nMaxMsgLength;

			int m_nSocketId;
			int m_nPortNumber;
			sockaddr_in st_SocketAddress;
	};
};
#endif __MY_CLIENT_