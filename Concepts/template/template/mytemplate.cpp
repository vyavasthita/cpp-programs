#include "mytemplate.h"
#include <conio.h>

template <typename T> TCMyTemplate<T>::TCMyTemplate()
{
}

template <typename T> TCMyTemplate<T>::~TCMyTemplate()
{
}

template <typename T> int TCMyTemplate<T>::addNum(T& a, T&b)
{
	int sum = a + b;
	return sum;
}

void main()
{
	int i = 5, j = 7;

	TCMyTemplate<int> object;
	int sum = object.addNum(i, j);
	std::cout << sum;
	getch();
}