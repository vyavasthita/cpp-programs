#ifndef __TCP_HOST_
#define __TCP_HOST_

#include <WinSock2.h>
#include <iostream>

namespace TCPComm
{
	const unsigned int m_const_unHostNameLength = 64;

	class CTCPHost
	{
		public:
			CTCPHost();
			char* GetHostName();
			char* GetHostIPAddress();
			std::string GetTCPErrorMsg();

		private:
			struct hostent *st_HostName;    // Entry within the host address database
	};
};

#endif __TCP_HOST_