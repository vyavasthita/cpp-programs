#include <iostream>

class CBucketSort
{
	public:
		CBucketSort();
		~CBucketSort();

		void userConsole();

		void sort();

		void swap(int & val1, int & val2);

		void createBucket(int item);

		int chooseBucket(int item);

		void fillBucket(int item, int bucketIndex);

		void sortBucket();

		void printArray();

	private:	
		int* bucketArray;
		int** bucketData;
		int arraySize;
};