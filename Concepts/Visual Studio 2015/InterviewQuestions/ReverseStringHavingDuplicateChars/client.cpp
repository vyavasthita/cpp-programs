/*
print all the characters present in the given string only once in a reverse order. Time & Space complexity should not be more than O(N).
e.g.
1)Given a string aabdceaaabbbcd
the output should be - dcbae

2)Sample String - aaaabbcddddccbbdaaeee
Output - eadbc

3)I/P - aaafffcccddaabbeeddhhhaaabbccddaaaa
O/P - adcbhef

Source : https://www.careercup.com/question?id=5709246416027648
*/

#include "file.h"
#include <conio.h>
#include <string>


int main()
{
	std::string input;

	std::cout << "Enter input --> ";
	std::cin >> input;

	ReverseString ob(input);

	std::string output = ob.getReversedInput();

	//std::cout << "Ouput --> " << output;

	_getch();
	return 0;
}