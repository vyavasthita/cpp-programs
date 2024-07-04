#include <iostream>
#include <conio.h>
#include <deque>

using namespace std;

class MyClass
{
	public:
		MyClass(int i = 7);
		void fun1();
		void fun2();
};

MyClass::MyClass(int i)
{
}

void MyClass::fun1()
{
	cout << "Fun1\n";
}

void MyClass::fun2()
{
	this->fun1();
}

void myfun(const char* ptr)
{
	//ptr[2] = ' ';
}

void main()
{
	int *ptr = new int;
	*ptr = 10;

	std::cout << *ptr << ::std::endl;

	int arr[4] = {1, 2, 3, 4};
	int *p = new int[4];

	std::cout << "array size -> " << sizeof(arr) << std::endl;
	std::cout << "pointer size -> " << sizeof(p) << std::endl;

	const char* ch;
	ch = "x";

	char* const ch2 = "abc";
	char carr[4] = {'a', 'b', 'c'};
	myfun(carr);


	p[0] = 111;

	std::cout << "first element of array is : " << p[0] << std::endl;

	MyClass ob;
	ob.fun2();
	getch();
}