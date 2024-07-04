#include <iostream>
#include <fstream>

#ifndef __FILE_PAR_H_
#define __FILE_PAR_H_

namespace MyThread
{
	class FileParser
	{
		public:
			
			~FileParser();

			static FileParser& getInstance();

			void ParseFile();

			void OpenFile(const std::string &const_r_strFileName);

			void ReadFile();

			void CloseFile();

			void WriteToFile(const char* const_cpThreadName, const char* const_cpFileContent);

		protected:
			FileParser();
			std::fstream m_fFileStream;

			static std::string m_stat_strFilePath;
	};
};
#endif __FILE_PAR_H_
