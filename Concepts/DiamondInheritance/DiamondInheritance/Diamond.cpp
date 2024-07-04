#include <iostream>
#include <conio.h>

using namespace std;


class A
{
public:
	int var;
};

class B:public A
{
};

class C:public A
{
};

class D: public B, public c
{
	
};

void main()
{
	D obj;
	obj.var;
};
