#include <iostream>

class Merging
{
	public:
		Merging();
		~Merging();

		void divide(int* input, int start, int end);
		void conquer(int* input, int start, int mid, int end);

		void printInput(int input[], int size);

	private:
		int* leftInput;
		int* rightInput;
};