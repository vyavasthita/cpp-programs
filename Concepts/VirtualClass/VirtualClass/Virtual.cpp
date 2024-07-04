#include <iostream>
#include <conio.h>

using namespace std;

class A
{
	
	public:
		A()
		{  int i;
				cout<<"A"<<endl;
		};
};

class B: public A
{
	public:
		B()
		{
			cout<<"B"<<endl;
		};
};

class C:public A
{
	public:
		C()
		{
			cout<<"C"<<endl;
		};
};

class D:public C, public B
{
	public:
		D()
		{
			cout<<"D";
		};
};

void main()
{
	D d;
	getch();
}