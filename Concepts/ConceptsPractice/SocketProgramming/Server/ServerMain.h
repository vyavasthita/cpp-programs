#ifndef __SERVER_MAIN_
#define __SERVER_MAIN_

#include "MyServer.h"
#include <conio.h>

using namespace SocketNamespace;

class CServerMain
{
	public:
		CServerMain();
		void SendMsg();
		void StartServer();

	private:
		const std::string m_const_strLocalHostIPAddr;
		std::string m_strLocalHostName;
		std::string m_strClientHostName;

		CMyServer m_oCMyServer;
};
#endif __SERVER_MAIN_