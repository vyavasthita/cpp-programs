//#include "logger.h"
//
//using namespace ThreadNameSpace;
//
//
//CLogger* CLogger::m_CLogger = NULL;
//
//CLogger::~CLogger()
//{
//	if (m_CLogger != NULL)
//	{
//		delete m_CLogger;
//		m_CLogger = NULL;
//	}
//}
//
//CLogger* CLogger::getInstance()
//{
//	if (m_CLogger == NULL)
//	{
//		m_CLogger = new CLogger();
//	}
//	return m_CLogger;
//}