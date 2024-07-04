#include <iostream>
#include <conio.h>

using namespace std;

class base
{
	public:
		base(int);
		base operator = (const base &);
	private:
		int *arr;
		int sizeOfArray;
};

base::base(int size)
{
	sizeOfArray = size;
	arr = new int[size];
}

base base::operator = (const base &b)
{
	if(this == &b)
	{
		return *this;
	}
	delete[] arr;

	sizeOfArray = b.sizeOfArray;

	for(int i = 0; i < sizeOfArray; i++)
	{
		arr[i] = b.arr[i];
	}
	return *this;
}

int main()
{	
	base s1(5), s2(10);
	s1 = s2;
	getch();
    return 0;
}
