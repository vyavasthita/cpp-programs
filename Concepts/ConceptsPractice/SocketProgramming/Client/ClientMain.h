#ifndef __CLIENT_MAIN_
#define __CLIENT_MAIN_

#include "MyClient.h"
#include <iostream>
#include <conio.h>

using namespace SocketNamespace;

class CClientMain
{
	public:
		CClientMain();
		void SendMsg();
		void StartClient();

	private:
		const std::string m_const_strServerIPAddr;
		std::string m_strLocalHostName;
		std::string m_strServerHostName;

		CMyClient m_oCMyClient;
};
#endif __CLIENT_MAIN_