/*
Name: Dilip Sharma
Summary: I am putting all words into a STL vector. Then i am removing the delimiter from each word in vector.
		Then i am putting all words into an hashtable. 
*/

#include <stdio.h>
#include <sstream>
#include <vector>
#include <algorithm>
#include "anagram.h"
#include <conio.h>

bool invalid_char(char c)
{
	return !(c>=97 && c<= 122);
}

void CAnagram::removeDelimiter(std::vector<std::string> & vecWords)
{
    for (std::vector<std::string>::iterator wordsInterator = vecWords.begin(); wordsInterator != vecWords.end(); wordsInterator ++)
    {
        (*wordsInterator).erase(remove_if((*wordsInterator).begin(), (*wordsInterator).end(), invalid_char), (*wordsInterator).end());
    }
}

/* Remove additional printf/scanf statements before submission. */
int CAnagram::NumberOfAnagrams(std::string& inputStr)
{
    std::istringstream sstrStream(inputStr);
    std::string strWordInLine = "";
    
    std::vector<std::string> vecInputWords;
    
    while(!sstrStream.eof())
    {
        getline(sstrStream, strWordInLine, ' ');
        
        vecInputWords.push_back(strWordInLine);
    }
    
    removeDelimiter(vecInputWords);

	for (std::vector<std::string>::iterator wordsInterator = vecInputWords.begin(); wordsInterator != vecInputWords.end(); wordsInterator ++)
	{
		m_hashTable.insertRecord(*wordsInterator);
	}

	int noOfAnagrams = 0;

	noOfAnagrams = m_hashTable.NumberOfAnagrams();
    
    // Your Code Goes here
    return noOfAnagrams;
}

// Do not modify main() when submitting.
int main() 
{
	CAnagram oCAnagram;

	std::string str = "long lives are elvis2";
    char inputStr[10000];
    //cin.getline(inputStr, sizeof(inputStr));
    std::cout<<oCAnagram.NumberOfAnagrams(str);

	getch();
}