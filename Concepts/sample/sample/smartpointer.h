#include <iostream>

template <typename T> class mysmartpointer
{
	public:
		mysmartpointer();
		~mysmartpointer();

		mysmartpointer(const T* ptr);
	private:
		const T* smart;
};