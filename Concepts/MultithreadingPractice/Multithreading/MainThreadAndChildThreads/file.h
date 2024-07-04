#pragma once
#include <fstream>
#include <iostream>

using namespace std;


class MyFile
{
	public:
		MyFile();
		void writeToFile(const char* info, int count);
		void readFile();

	private:
		ofstream m_ofFileStream;
		ifstream m_ifFileStream;
		const char* m_pcFilePath;
};