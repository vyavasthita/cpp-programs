#include "ServerLog.h"
#include <string>
#include <Windows.h>

using namespace SocketConnection;

std::ofstream CServerLog::m_stat_oFileStream;
bool CServerLog::m_stat_bCreated = false;

const std::string CServerLog::m_stat_const_strServerLogFileName = "ServerLog.txt";
std::string CServerLog::m_stat_strServerLogFilePath = "";

CServerLog* CServerLog::m_stat_opCServerLog = NULL;

CServerLog::CServerLog()
{
	char szBuffer[MAX_PATH];

    GetModuleFileName(NULL, szBuffer, MAX_PATH);
    std::string::size_type pos = std::string(szBuffer).find_last_of( "\\/" );

	std::string strLogFilePath = std::string(szBuffer).substr(0, pos) + '/' + m_stat_const_strServerLogFileName; 

	m_stat_oFileStream.open(strLogFilePath, std::ios::app);

	if (m_stat_oFileStream.bad())
	{
		throw "Server Log File Open Error";
	}
}

CServerLog::~CServerLog()
{
	if (m_stat_oFileStream.is_open())
	{
		m_stat_oFileStream.close();
	}

	if (m_stat_opCServerLog != NULL)
	{
		delete m_stat_opCServerLog;
		m_stat_opCServerLog = NULL;
	};
}

CServerLog* CServerLog::GetInstance()
{
	if (m_stat_bCreated == false)
	{
		m_stat_opCServerLog = new CServerLog;
		m_stat_bCreated = true;
	}
	return m_stat_opCServerLog;
}

void CServerLog::Log(const char *const_pcErrorMsg)
{
	m_stat_oFileStream << const_pcErrorMsg << std::endl;
}