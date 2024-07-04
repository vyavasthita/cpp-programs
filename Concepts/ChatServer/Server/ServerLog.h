#ifndef __SERV_LOG_
#define __SERV_LOG_

#include <iostream>
#include <fstream>

namespace SocketConnection
{
	class CServerLog
	{
		public:
			static CServerLog* GetInstance();
			void Log(const char *const_pcErrorMsg);

			static std::string m_stat_strServerLogFilePath;

		private:
			CServerLog();
			~CServerLog();

			static CServerLog* m_stat_opCServerLog;
			static bool m_stat_bCreated;

			static std::ofstream m_stat_oFileStream;

			static const std::string m_stat_const_strServerLogFileName;
	};
};

#endif __SERV_LOG_