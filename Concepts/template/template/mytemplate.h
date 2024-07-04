#include <iostream>

template <typename T> class TCMyTemplate
{
	public:
		TCMyTemplate();
		~TCMyTemplate();

		int addNum(T& a, T&b);
};