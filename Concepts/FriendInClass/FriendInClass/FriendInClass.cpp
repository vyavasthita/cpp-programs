#include <iostream>
#include <conio.h>

using namespace std;

class Second
{
	int iSecond;

	public:
		Second()
		{
			iSecond = 7;
		}	
		void funSecond();
};


class First
{
	int iFirst;

	public:
		First()
		{
			iFirst = 5;
		}
		friend void Second::funSecond();
};

void Second::funSecond()
{
	First obj;
	
	cout<<"iFirst is : "<<obj.iFirst;
}

void main()
{
	Second secObj;
	secObj.funSecond();
	getch();
}