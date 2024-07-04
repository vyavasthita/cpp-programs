#include <iostream>
#include <conio.h>

int getNum(int a, int b)
{
	return 5; 
}

void pointerFun(int (*p)(int, int))
{
	int res = (*p)(50, 100);

	std::cout << res;
}

class CPointer
{
	public:
		CPointer(){};
		~CPointer(){};

		void classFun();
};

void CPointer::classFun()
{
	int (*ptr)(int, int) = &getNum;

	pointerFun(ptr);
}

void main()
{
	CPointer ob;
	ob.classFun();

	getch();
}

