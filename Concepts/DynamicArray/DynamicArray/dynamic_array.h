#ifndef __DY_ARR_H_
#define __DY_ARR_H_

#include <iostream>

enum e_choice
{
	INSERT = 1,
	DELETE,
	SEARCH,
	PRINT,
	COUNT,
	EXIT
};

class DArray
{
	public:
		DArray();
		DArray(int size);
		~DArray();

		void init();
		void pushBack(int item);
		void deleteItem(int item);
		void resizeArray(short int sizeVar);

		bool search(int item);
		void print();
		int size();

		void clearScreen();
		
	private:
		int *dynamicArray;
		int miSize;
		static int siCurrArrIndex;
		int iSearchItemIndex;
};
#endif __DY_ARR_H_