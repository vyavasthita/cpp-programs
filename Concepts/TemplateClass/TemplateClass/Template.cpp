#include <iostream>
#include <conio.h>

using namespace std;

template <typename family, int size> class MyClass
{
	public:
		void fun();
		void show();
	private:
		family arr[size];
};

template <class family, int size> void MyClass<family, size>::fun()
{
	for(unsigned int ui = 0; ui < size; ui++)
	{
		arr[ui] = ui;
	}
}

template <class family, int size> void MyClass <family, size>::show()
{
	for(unsigned int ui = 0; ui < size; ui++)
	{
		cout<<arr[ui]<<" ";
	}
}
void main()
{
	MyClass<int, 10> ob;
	ob.fun();
	ob.show();
	getch();
}