#include "file.h"

ReverseString::ReverseString(std::string input) :
	m_strInput(input)
{
	m_cpItems = new char[26];

	for (int i = 0; i < 26; i++)
	{
		m_cpItems[i] = NULL;
	}
}

void ReverseString::insertItem(char item)
{
	int key = getHashKey(item);

	if (m_cpItems[key] == NULL)
	{
		m_cpItems[key] = item;
	}
}

int ReverseString::getHashKey(char item)
{
	return (item - 97);
}

std::string ReverseString::getReversedInput()
{
	std::string strOutput;

	for (int i = 0; i < m_strInput.size(); i++)
	{
		insertItem(m_strInput[i]);
	}

	for (int i = 25; i >= 0; i--)
	{
		if (m_cpItems[i] != NULL)
		{
			std::cout << m_cpItems[i] << std::endl;
			strOutput.push_back(m_cpItems[i]);
		}
	}
	return strOutput;
}