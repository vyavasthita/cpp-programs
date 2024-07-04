#ifndef __MY_SERVER_
#define __MY_SERVER_

#include "MySocket.h"
#include <iostream>

namespace SocketConnection
{
	class CMyServer
	{
		public:
			CMyServer();

			void SocketConnection();
			void TerminateConnection();
			void TerminateApplication();

			void SetServerHostInfo();
			char* GetServerHostName();
			char* GetServerHostIPAddress();

			void ChatWithClient();

		private:
			CMySocket m_oCMySocket;
			const int m_const_nPortNumber;
			static const int m_stat_const_nHostNameLength;  
			hostent * m_p_stHostInfo;

			std::string m_strClientHostName;

			const int m_const_nMaxMsgLength;
	};
};
#endif __MY_SERVER_