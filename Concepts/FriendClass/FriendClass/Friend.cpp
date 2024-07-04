#include <iostream>
#include <conio.h>

using namespace std;

class First
{
	int iFirst;

	public:
		First()
		{
			iFirst = 5;
		}
		friend class Second;
};

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