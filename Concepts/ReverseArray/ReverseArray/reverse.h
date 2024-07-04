#include <iostream>

class CReverse
{
	public:
		CReverse();
		~CReverse();

		void userConsole();

		void reverseArray();

		void swapValues(int& a, int &b);

		void printValues();

	private:
		int* rev;
		int size;
};