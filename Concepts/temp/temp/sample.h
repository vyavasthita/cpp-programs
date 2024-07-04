#include <iostream>

template <typename T> class MyStack
{
	public:
		MyStack(T s);
		~MyStack();

		void push(T item);
		T pop();

	private:
		int tos;
		T *tArray;
		int size;
};