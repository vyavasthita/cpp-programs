#include <iostream>


class MyDLLClass
{
	public:
		__declspec(dllexport) int AddNumber(int, int);
};