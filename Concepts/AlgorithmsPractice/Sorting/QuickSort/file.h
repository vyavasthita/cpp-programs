#pragma once

#include <iostream>

class Quick
{
	public:
		Quick();
		~Quick();

		void quickSort(int* input, int start, int end);
		int partition(int* input, int start, int end);
		void swapNum(int& first, int& second);

		void printInput(int input[], int size);

	private:
		int* leftInput;
		int* rightInput;
};
