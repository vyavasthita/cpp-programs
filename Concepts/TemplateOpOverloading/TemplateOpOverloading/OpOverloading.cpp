#include "OpOverloading.h"
#include <conio.h>

template <typename T> TCOperaterOverloading<T>::TCOperaterOverloading() : value1(0), value2(0)
{
}

template <typename T> TCOperaterOverloading<T>::TCOperaterOverloading(T& v1, T& v2) : value1(v1), value2(v2)
{

}

template <typename T> TCOperaterOverloading<T>::~TCOperaterOverloading()
{
}

template <typename T> TCOperaterOverloading<T> TCOperaterOverloading<T>::operator + (const TCOperaterOverloading <T>& constOverloading)
{
	TCOperaterOverloading<T> oTCOperaterOverloading;

	oTCOperaterOverloading.value1 = value1 + constOverloading.value1;
	oTCOperaterOverloading.value2 = value2 + constOverloading.value2;

	return oTCOperaterOverloading;
}

template <typename T> TCOperaterOverloading<T> TCOperaterOverloading<T>::operator = (const TCOperaterOverloading <T>& constOverloading)
{
	value1 = constOverloading.value1;
	value2 = constOverloading.value2;

	return *this;
}

template <typename T> void TCOperaterOverloading<T>::printNumbers()
{
	std::cout << value1 << "," << value2;
}

void main()
{
	int i = 5, j = 7, k = 9, l = 11;

	TCOperaterOverloading<int> object1(i, j);
	TCOperaterOverloading<int> object2(k, l);

	TCOperaterOverloading<int> object3 = object1 + object2;

	object3.printNumbers();
	
	getch();
}