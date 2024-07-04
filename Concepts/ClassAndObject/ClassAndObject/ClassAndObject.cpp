#include <iostream>
#include <conio.h>


using namespace std;

class MyClass
{
	//private Members
	int iVar;
	double dVar;

	//public Members
	public:
		MyClass()
		{
			cout<<"Ctor : "<<endl;
		}
		~MyClass()
		{
			cout<<"Dtor : "<<endl;
		}
		void memberFun(int, double);
		void printValues();
		
};

void MyClass::memberFun(int i, double d)
{
	iVar = i;
	dVar = d;
}

void MyClass::printValues()
{
	cout<<iVar<<", "<<dVar<<endl;
}

int main(int argc, char *arr[])
{
	MyClass myClassObj1;	//Stack

	MyClass *myClassObj2 = new MyClass;	//Heap
	myClassObj1.memberFun(5, 5.5);

	myClassObj2->memberFun(10, 10.5);


	cout<<"Object 1's Values are\n";
	myClassObj1.printValues();

	
	cout<<"Object 2's Values are\n";
	myClassObj2->printValues();

	delete myClassObj2;	

	getch();
	
	return 0;
}