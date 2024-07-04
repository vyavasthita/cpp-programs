#include <iostream>
#include <conio.h>

using namespace std;
class MyClass 
{
	int *p;
	int size;

	public:
		MyClass(int sz) 
		{
			try 
			{
				p = new int[sz];
			} 
			catch (bad_alloc xa) 
			{
				cout << "Allocation Failure\n";
				exit(EXIT_FAILURE);
			}
			size = sz;
		}
		
		~MyClass() 
		{ 
			delete [] p; 
		}
		
		// copy constructor
		MyClass(const MyClass &a);
		
		void put(int i, int j) 
		{
			if(i>=0 && i<size)
				{
					p[i] = j;
				}
		}
		
		int get(int i) 
		{
			return p[i];
		}
};

// Copy Constructor
MyClass::MyClass(const MyClass &a) 
{
	int i;

	try 
	{
		p = new int[a.size];
	} 
	catch (bad_alloc xa) 
	{
		cout << "Allocation Failure\n";
		exit(EXIT_FAILURE);
	}

	for(i=0; i<a.size; i++) 
		{
			p[i] = a.p[i];
		}
}
int main()
{
	MyClass num(10);
	int i;

	for(i=0; i<10; i++)
		{
			num.put(i, i);
		}

	for(i=9; i>=0; i--)
		{
			cout << num.get(i);
		}

	cout << "\n";

	// create another MyClass and initialize with num
	MyClass x(num); // invokes copy constructor
	for(i=0; i<10; i++) 
		{	
			cout << x.get(i);
		}
	getch();
	return 0;
}