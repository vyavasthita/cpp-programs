#include <iostream>
#include <conio.h>

using namespace std;

class MyClass 
{
	int i;
	public:
		MyClass(int j) { i=j; }
		int get_i() { return i; }
};

int main()
{
	MyClass ob(88), *p;
	p = &ob; // get address of ob

	cout << p->get_i(); // use -> to call get_i()
	getch();
	return 0;
}