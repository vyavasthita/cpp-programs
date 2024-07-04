#pragma once

#include <iostream>


class Logger
{
	public:
		static Logger* getInstance();
		~Logger();

		static void Log(const char* info);
	private:
		Logger();

		static const char* m_filePath;
		static Logger* m_Logger;
		static bool bInstance;
};
