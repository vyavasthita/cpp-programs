#include <iostream>
#include <conio.h>

using namespace std;

class CMyClass
{
	public:
		void* operator new(size_t size);
		void* operator new[](size_t size);

		void operator delete(void* ptr);
		void operator delete[](void* ptr);
};

void* CMyClass::operator new(size_t size)
{
	void* ptr = malloc(size);
	return ptr;
}

void* CMyClass::operator new[](size_t size)
{
}

void main()
{
	CMyClass* ob = new CMyClass;
	getch();
}