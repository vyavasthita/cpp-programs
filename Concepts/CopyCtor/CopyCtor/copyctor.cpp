#include <iostream>
#include <conio.h>

using namespace std;

class base
{
	public:
		// constructor
		base(int s)
		{
			cout<<"Ctor\n";
			size = s;
			ptr = new int[size];
		}
		base(const base &b)
		{
			cout<<"copy Ctor\n";
			ptr = new int[sizeof(b.ptr)];

			for(int i = 0; i < sizeof(b.ptr); i++)
			{
				ptr[i] = b.ptr[i];
			}
		}
		// destructor
		~base()
		{
			cout<<"Dtor\n";
			delete ptr;
		}
		void fun(base);

		int *ptr;
		int size;
};

void base::fun(base b)
{
	
}
void main()
{{
	int size = 5;
	base ob1(size);
	
	for(int i = 0; i < size; i++)
	{
		ob1.ptr[i] = i + 1;
	}

	base ob2 = ob1;

	for(int i = 0; i < size; i++)
	{
		//cout<<ob2.ptr[i]<<" ";
	}
	//ob1.fun(ob1);
}
	getch();
}