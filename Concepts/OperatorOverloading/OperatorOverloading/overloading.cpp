#include <iostream>
#include <exception>
#include <conio.h>
#include <sstream>
#include <string>

using namespace std;

class MyClass
{
	public:
		MyClass();
		~MyClass()
		{
		}
		friend ostream& operator << (ostream& stream, const MyClass& object);
	private:
		int i, j;
};

MyClass::MyClass()
{
	i = 5;
	j = 7;
}

ostream& operator << (ostream& stream, const MyClass& object)
{
	stream << object.i << "," << object.j << endl;
	return (stream);
}

void main()
{
	MyClass ob;
	cout << ob;

	getch();
}