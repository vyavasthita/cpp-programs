#include <iostream>
#include <conio.h>

using namespace std;

void main()
{
	int iVar = 5;
	int *iPtr = &iVar;
	int **iDoublePtr = &iPtr;

	cout<<"Addres of iVar is : "<<iPtr<<endl;
	cout<<"Value of iVar is : "<<*iPtr<<endl;

	cout<<"Addres of iPtr is : "<<iDoublePtr<<endl;
	cout<<"Value of iPtr is : "<<*iDoublePtr<<endl;

	cout<<"Value of iVar using double pointer is : "<<**iDoublePtr<<endl;

	getch();
}