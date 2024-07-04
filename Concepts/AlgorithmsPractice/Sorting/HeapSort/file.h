#pragma once

#include <iostream>

class Heap
{
	public:
		Heap(int* input, int size);
		~Heap();

		void buildHeap(int index);
		void swapElements(int* first, int* second);

		void makeAHeap();

		int getMaxElement();
		void heapSort();
		void printElements();
		int getIndexByNodeValue(int value);
		void increaseValueOfNode(int value, int newValue);

	private:
		int* m_npInput;
		int m_nInputSize;
		int m_nHeapSize;
		int m_nNonLeafNode;
};

