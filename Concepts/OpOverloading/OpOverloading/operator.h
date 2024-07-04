#include <iostream>

//COpOverloading operator+(const COpOverloading& lhs, const COpOverloading& rhs);

class COpOverloading
{
	public:
		COpOverloading();
		COpOverloading(int i);
		friend COpOverloading operator+(const COpOverloading& lhs, const COpOverloading& rhs);

		void printData();

	private:
		int a;//, b;
};