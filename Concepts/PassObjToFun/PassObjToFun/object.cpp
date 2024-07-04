
#include <iostream>
#include <conio.h>
#include <typeinfo>

using namespace std;

void main()
{
	int var = 10;
	int *p;
	

	p = reinterpret_cast<int*>(var);
	if(p)
	{
		cout<<"Success "<<typeid(*p).name()<<endl;
	}

	getch();
}