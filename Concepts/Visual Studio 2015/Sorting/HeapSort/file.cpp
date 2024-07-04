#include "file.h"

Heap::Heap(int* input, int size) : 
	m_npInput(input), m_nInputSize(size), m_nHeapSize(m_nInputSize),
	m_nNonLeafNode((m_nInputSize / 2) - 1)
{
	m_npInput = new int[m_nInputSize];

	for (int i = 0; i < m_nInputSize; i++)
	{
		m_npInput[i] = input[i];
	}
}

Heap::~Heap()
{
	delete[] m_npInput;
	m_npInput = NULL;
}

void Heap::swapElements(int* first, int* second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

void Heap::buildHeap(int index)
{
	if (index >= m_nInputSize / 2)
	{
		return;
	}

	int leftChildIndex = index * 2 + 1;
	int rightChildIndex = leftChildIndex + 1;

	int maxIndex = index;

	if ((leftChildIndex != m_nInputSize) && (m_npInput[leftChildIndex] > m_npInput[index]))
	{
		maxIndex = leftChildIndex;		
	}
	if ((rightChildIndex != m_nInputSize) && (m_npInput[rightChildIndex] > m_npInput[maxIndex]))
	{
		maxIndex = rightChildIndex;
	}

	if (maxIndex != index)
	{
		swapElements(&m_npInput[maxIndex],
			&m_npInput[index]);

		buildHeap(maxIndex);
	}		
}

void Heap::makeAHeap()
{
	while (true)
	{		
		if (m_nNonLeafNode == -1)
		{
			break;
		}
	
		buildHeap(m_nNonLeafNode--);
	}
}

int Heap::getMaxElement()
{
	return m_npInput[0];
}

void Heap::printElements()
{
	for (int i = 0; i < m_nHeapSize; i++)
	{
		std::cout << m_npInput[i] << " ";
	}
}

void Heap::heapSort()
{
	int lastIndex = m_nInputSize - 1;

	while (true)
	{
		if (lastIndex == -1)
		{
			break;
		}
		swapElements(&m_npInput[0], &m_npInput[lastIndex--]);
		--m_nInputSize;
		buildHeap(0);
	}
}

int Heap::getIndexByNodeValue(int value)
{
	for (int i = 0; i < m_nHeapSize; i++)
	{
		if (m_npInput[i] == value)
		{
			return i;
		}
	}
	return -1;
}

void Heap::increaseValueOfNode(int value, int newValue)
{
	int index = getIndexByNodeValue(value);

	m_npInput[index] = newValue;

	int parentNodeIndex = 0;

	if (index % 2 == 0 && index != 0)
	{
		parentNodeIndex = (index / 2) - 1;
	}
	else
	{
		parentNodeIndex = index / 2;
	}
	std::cout << "Parent Index " << parentNodeIndex << std::endl;
	m_nNonLeafNode = parentNodeIndex;
	makeAHeap();
}