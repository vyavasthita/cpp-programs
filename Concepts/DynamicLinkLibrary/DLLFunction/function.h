#include <iostream>

// This class is exported from the MathFuncsDll.dll
class MyMathFuncs
{
	public: 
		// Returns a + b
		static __declspec(dllexport) void fun(); 
};
