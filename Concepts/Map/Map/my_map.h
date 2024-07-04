#include <iostream>

template <typename key, typename value> class MyMap
{
	public:
		MyMap();
		~MyMap();

	private:
		key k;
		value v;

		MyMap<key, value>* left;
		MyMap<key, value>* right;
};

