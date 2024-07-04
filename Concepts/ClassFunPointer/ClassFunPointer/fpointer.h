#include <iostream>

class CPointer
{
	public:
		CPointer();
		~CPointer();
		int addNum(int i, int j);

		void otherFun(int (CPointer::*ptr)(int, int));

	private:
		int a, b;
};