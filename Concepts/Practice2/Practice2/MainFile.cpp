#include <iostream>
#include <conio.h>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;

bool my_fun(char c)
{
	/*bool b;

	int asc = int(c);

	if (asc <=122 && asc >=97)
	{
		return true;
	}
	else
	{
		return false;
	}*/
	return !(c>=97 && c<= 122);
}

void removeDelimiter(std::vector<std::string> & vecWords)
{
    for (std::vector<std::string>::iterator wordsInterator = vecWords.begin(); wordsInterator != vecWords.end(); wordsInterator ++)
    {
        /*for (int wordIterator = 0; wordIterator < (*wordsInterator).length(); wordIterator++)
        {
            
        }*/
		(*wordsInterator).erase(remove_if((*wordsInterator).begin(), (*wordsInterator).end(), my_fun), (*wordsInterator).end());
    }

	for (std::vector<std::string>::iterator wordsInterator = vecWords.begin(); wordsInterator != vecWords.end(); wordsInterator ++)
    {
		std::cout << *wordsInterator << std::endl;
	}
}


int main()
{   
	string str = "hi3 how 1are you33 i am fine";

	std::vector<string> v;

	v.push_back("hi3");
	v.push_back("how");
	v.push_back("1are");
	v.push_back("you33");
	v.push_back("i");
	v.push_back("am");

		
	removeDelimiter(v);
	

	getch();
  
    return 0;
}