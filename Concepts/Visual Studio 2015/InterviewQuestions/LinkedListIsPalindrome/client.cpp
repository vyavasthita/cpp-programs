/*
Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:
- Expected solution is linear in time and constant in space.

For example,

List 1–>2–>1 is a palindrome.
List 1–>2–>3 is not a palindrome.

Source : http://www.crazyforcode.com/check-singly-linked-list-palindrome/
*/

#include "file.h"
#include <conio.h>
#include <iostream>


using namespace LINKEDLIST;
using namespace std;


int main()
{
	LinkedList ob;

	ob.addNode(1);
	ob.addNode(2);
	ob.addNode(3);
	ob.addNode(4);
	ob.addNode(5);
	ob.addNode(6);
	ob.addNode(7);
	ob.addNode(8);
	ob.addNode(9);
	ob.addNode(10);
	ob.addNode(11);
	ob.addNode(12);

	ob.traverseList();

	/*bool res = ob.isPalindrome();

	if (res)
	{
		cout << "Palindrom\n";
	}
	else
	{
		cout << "Not Palindrom\n";
	}*/

	_getch();
}