#include <iostream>

extern "C"
{
	class CAddition
	{
		public:
			__declspec(dllexport) int addNum(int a, int b);
	};
}