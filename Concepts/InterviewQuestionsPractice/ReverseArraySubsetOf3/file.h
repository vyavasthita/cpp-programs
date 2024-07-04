#pragma once

#include <iostream>

using namespace std;

class MyArray
{
	public:
		MyArray();
		~MyArray() {}
		void reverseArray(int* input, int size, int chunk);
		void reverseArrayInChunks(int* input, int start, int end);
		void swapNum(int * first, int* second);
		void printArray(int* input, int size);

};
