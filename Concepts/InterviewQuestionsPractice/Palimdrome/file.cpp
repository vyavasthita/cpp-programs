#include <iostream>
#include <conio.h>

using namespace std;


bool isPalindrome(int number)
{
	int div = 0;
	int rev = 0;
	int base = 1;
	int num = number;

	while (num)
	{
		//cout << num << " ";
		div = num % 10;
		num = num / 10;
		rev = rev * 10 + div;
		//base = base * 10;
		cout << rev << " " << endl;
	}

	if (number == rev)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int number = 0;

	cout << "Enter a number : ";
	cin >> number;

	if (isPalindrome(number))
	{
		cout << "Number is Palindrome\n";
	}
	else
	{
		cout << "Number is NOT Palindrome\n";
	}
	_getch();
}