#include "file.h"

using namespace NamespaceCountChar;
using namespace std;


CountChar::CountChar()
{
	m_cCharsDetails = new INFO[26];

	for (int i = 0; i < 26; i++)
	{
		m_cCharsDetails[i].identity = NULL;
		m_cCharsDetails[i].count = 0;
	}
}

short CountChar::getHashKey(char cChar)
{
	return (int(cChar) - 97);
}

short CountChar::fetchCharCount()
{
	for (int i = 0; i < 26; i++)
	{
		if (m_cCharsDetails[i].identity != NULL)
		{
			cout << "Char : " << m_cCharsDetails[i].identity << ", Count : " << m_cCharsDetails[i].count << endl;
		}
	}
	return 0;
}

void CountChar::insertCharInfo(char cChar)
{
	short key = getHashKey(cChar);

	if (m_cCharsDetails[key].identity == NULL)
	{
		m_cCharsDetails[key].identity = cChar;
	}
	++(m_cCharsDetails[key].count);
}