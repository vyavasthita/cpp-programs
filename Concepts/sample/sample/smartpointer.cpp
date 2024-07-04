#include "smartpointer.h"
#include <conio.h>

using namespace std;

template <typename T> mysmartpointer<T>::mysmartpointer()
{
}

template <typename T> mysmartpointer<T>::mysmartpointer(const T* ptr) : smart(ptr)
{
	
}

template <typename T> mysmartpointer<T>::~mysmartpointer()
{
	if (smart != NULL)
	{
		delete smart;
		smart = NULL;
		cout << "Dtor called\n";
	}
}

void main()
{
	{
		int *p = new int;

		mysmartpointer<int> s1(p);
	}

	getch();
}