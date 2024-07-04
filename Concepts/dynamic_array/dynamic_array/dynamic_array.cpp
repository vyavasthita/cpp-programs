#include <iostream>
#include <conio.h>
#include <exception>


using namespace std;

class myarray
{
	public:	
		myarray();
		~myarray();
		int getElement(int);
		void setElement(int, int);
		int& operator [] (int);
		void resize(int x);
		void print();
	private:
		int mSize;
		static const int kSize = 10;
		int * pArray;
};

int& myarray::operator[] (int at)
{
	if(at >= mSize)
	{
		resize(at + kSize);
	}
	return pArray[at];
}
myarray::myarray()
{
	mSize = kSize;
	pArray = new int[mSize];
}

myarray::~myarray()
{
	delete [] pArray;
}

void myarray::setElement(int at, int value)
{
	if(at >= mSize)
	{
		resize(at + kSize);
	}
	pArray[at] = value;
}


int myarray::getElement(int at)
{
	if(at >= mSize)
	{
		cout<<"Array Index out of bound exception : getElement\n";
		return 0;
	}
	return (pArray[at]);
}

void myarray::resize(int newsize)
{
	int *newArray = new int[newsize];

	for(int i = 0; i < mSize; i++)
	{
		newArray[i] = pArray[i];
	}
	mSize = newsize;
	delete [] pArray;
	pArray = newArray;
}

void myarray::print()
{
	cout<<"Elements are : \n";

	for(int i = 0; i < mSize; i++)
	{
		cout<<pArray[i]<<" ";
	}
}

int main()
{
	myarray ob;
	
	for(int i = 0; i < 20; i++)
	{
		ob[i] = i;
	}
	ob.print();
    getch();
}