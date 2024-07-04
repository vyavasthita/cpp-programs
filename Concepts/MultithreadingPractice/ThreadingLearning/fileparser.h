#include <iostream>
#include <fstream>
#include "mutex.h"


#ifndef __FILE_PARSER_H_
#define __FILE_PARSER_H_

namespace ThreadNameSpace
{
	class CFileParser
	{
		public:
			CFileParser(CMutex* pMutex);
			~CFileParser();

			void openFile();
			void readFile();
			void writeToFile(char* cpThreadName, const char* cpContent);
			void closeFile();

		private:
			CMutex* m_cpMutex;

			static const char* m_const_cpFilePath;
			std::fstream m_fileStream;
	};
};

#endif __FILE_PARSER_H_ 