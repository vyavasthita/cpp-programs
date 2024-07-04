#include <iostream>

template <typename T> class TCOperaterOverloading
{
	public:
		TCOperaterOverloading();
		TCOperaterOverloading(T& v1, T& v2);
		~TCOperaterOverloading();

		TCOperaterOverloading<T> operator + (const TCOperaterOverloading<T>& constOverloading);
		TCOperaterOverloading<T> operator = (const TCOperaterOverloading<T>& constOverloading);

		void printNumbers();

	private:
		T value1;
		T value2;
};