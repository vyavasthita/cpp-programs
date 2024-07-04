#include <iostream>
#include <conio.h>
#include <stdexcept>

using namespace std;


class myclass
{
	public:
		myclass(int n)
		{
			size = n;
			arr = new int[n];
		}

		myclass& operator = (const myclass& ob);
		void fillData();

		void print();


	private:
		int *arr;
		int size;
};

void myclass::fillData()
{
	for(int i = 0; i < size; ++i)
	{
		arr[i] = i + 1;
	}
}

myclass& myclass::operator = (const myclass& ob)
{
	if(this == &ob)
	{
		return *this;
	}

	delete [] arr;
	
	arr = new int[ob.size];
	size = ob.size;

	for(int i = 0; i < size; ++i)
	{
		arr[i] = ob.arr[i];
	}

	return *this;
}

void myclass::print()
{
	cout<<"Values are\n";

	for(int i = 0; i < size; ++i)
	{
		cout<<arr[i]<<" ";
	}
}

void main()
{
	myclass first(5);
	myclass second(10);

	second = first;
	second.print();

	getch();
}