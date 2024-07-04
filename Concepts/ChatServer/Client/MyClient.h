#ifndef __MY_CLIENT_
#define __MY_CLIENT_

#include "MySocket.h"
#include <iostream>

namespace SocketConnection
{
	class CMyClient
	{
		public:
			CMyClient();

			void SocketConnection();
			void TerminateConnection();
			void TerminateApplication();

			void SetClientHostInfo();
			void SetServerHostInfo(const char *const_pcServerIPAddr);

			char* GetClientHostName();
			char* GetClientHostIPAddress();

			char* GetServerHostName();
			char* GetServerHostIPAddress();

			void ChatWithServer();

		private:
			CMySocket m_oCMySocket;
			const int m_const_nPortNumber;
			static const int m_stat_const_nHostNameLength;

			hostent *m_p_stClientHostInfo, *m_p_stServerHostInfo;

			const char* m_const_pcServerIPAddr;

			char *m_pcLocalHostName, *m_pcServerHostName;

			const int m_const_nMaxMsgLength;
	};
};
#endif __MY_CLIENT_